#include<bits/stdc++.h>
using namespace std;
 
 int max_recur(int i , int j , vector<vector<int>>grid){
     if(j<0 || j>=grid[0].size())return -1e9;
     if(i==0)return grid[i][j];

     int u = grid[i][j] + max_recur(i-1,j,grid);
     int dl = grid[i][j] + max_recur(i-1,j-1,grid);
     int dr = grid[i][j] + max_recur(i-1,j+1,grid);

     return max(u,max(dl,dr));
 }

 int recur(vector<vector<int>>grid){
     int n =grid.size();
     int m = grid[0].size();

    int maxi = -1e9;
    for(int i=0;i<m;i++){
        maxi = max(maxi,max_recur(n-1,i,grid));
    }
    return maxi;
 }
 int max_memoi(int i , int j , vector<vector<int>>grid , vector<vector<int>>&dp){
     if(j<0 || j>=grid[0].size())return -1e9;
     if(i==0)return grid[i][j];

        if(dp[i][j] != -1)return dp[i][j];

     int u = grid[i][j] + max_memoi(i-1,j,grid,dp);
     int dl = grid[i][j] + max_memoi(i-1,j-1,grid,dp);
     int dr = grid[i][j] + max_memoi(i-1,j+1,grid,dp);

     return dp[i][j] = max(u,max(dl,dr));
 }

 int memoi(vector<vector<int>>grid){
     int n =grid.size();
     int m = grid[0].size();

     vector<vector<int>>dp(n,vector<int>(m,-1));

    int maxi = -1e9;
    for(int i=0;i<m;i++){
        maxi = max(maxi,max_memoi(n-1,i,grid,dp));
    }
    return maxi;
 }

 int tabulation(vector<vector<int>>grid){
     int n = grid.size();
     int m = grid[0].size();

     vector<vector<int>> dp(n,vector<int>(m,0));

     for(int j=0 ; j<m;j++){
         dp[0][j] = grid[0][j];
     }
     for(int i=1;i<n;i++){
         for(int j=0;j<m;j++){
             int d = grid[i][j] + dp[i-1][j];
             int dl = grid[i][j];
             if(j>0)dl += dp[i-1][j-1];
             else{
                 dl+= -1e9;
             }
             int dr = grid[i][j];
             if(j+1<m){
                 dr+= dp[i-1][j+1];
             }
             else{
                 dr += -1e9;
             }
             dp[i][j] = max(d,max(dl,dr));
         }
     }
     int maxi = -1e9;
     for(int i=0;i<m;i++){
         maxi = max(maxi,dp[n-1][i]);
     }
     return maxi;
 }

 int space_optimised(vector<vector<int>>grid){
     int n = grid.size();
     int m = grid[0].size();

     vector<int> prev(m,0),curr(m,0);

     for(int j=0 ; j<m;j++){
         prev[j] = grid[0][j];
     }
     for(int i=1;i<n;i++){

         for(int j=0;j<m;j++){
             int d = grid[i][j] + prev[j];
             int dl = grid[i][j];
             if(j>0)dl += prev[j-1];
             else{
                 dl+= -1e9;
             }
             int dr = grid[i][j];
             if(j+1<m){
                 dr+= prev[j+1];
             }
             else{
                 dr += -1e9;
             }
             curr[j] = max(d,max(dl,dr));
         }
         prev = curr;
     }
     int maxi = -1e9;
     for(int i=0;i<m;i++){
         maxi = max(maxi,prev[i]);
     }
     return maxi;
 }
 
int main()
{
    vector<vector<int>>grid{{4,1,5,1},{6,2,7,2},{3,4,6,3},{2,1,4,5}};

    cout<<"max path sum :- (Recurssion) "<<recur(grid)<<endl;
    cout<<"max path sum :- (memoi) "<<memoi(grid)<<endl;
    cout<<"max path sum :- (tabulation) "<<tabulation(grid)<<endl;
    cout<<"max path sum :- (space optimised) "<<space_optimised(grid)<<endl;
 
    return 0;
}