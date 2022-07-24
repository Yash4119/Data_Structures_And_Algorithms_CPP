#include<bits/stdc++.h>
using namespace std;
 
 int min_path(vector<vector<int>>&grid , int m , int i , int j ){
     if(i==m-1)return grid[i][j];

     int d = grid[i][j] + min_path(grid,m,i+1,j);
     int dg = grid[i][j] + min_path(grid,m,i+1,j+1);

     return min(d,dg); 
 }

 int min_path_memoi(vector<vector<int>>&grid, vector<vector<int>>&dp , int m , int i ,int j){
     if(i==m-1)return grid[i][j];

     if(dp[i][j]!=-1)return dp[i][j];

     int d = grid[i][j] + min_path_memoi(grid,dp,m,i+1,j);
     int dg = grid[i][j] + min_path_memoi(grid,dp,m,i+1,j+1);

     return dp[i][j] = min(d,dg);
 }

 int memoi(vector<vector<int>>&grid , int m){
     vector<vector<int>>dp(m,vector<int>(m,-1));
     return min_path_memoi(grid,dp,m,0,0);
 }

 int Tabulation(vector<vector<int>>&grid , int m){
     vector<vector<int>>dp(m,vector<int>(m,0));
     for(int j=0;j<m;j++){
         dp[m-1][j] = grid[m-1][j];
     }

     for(int i=m-2; i>=0 ; i--){
         for(int j=i;j>=0;j--){
             int d = grid[i][j] + dp[i+1][j];
             int dg = grid[i][j] + dp[i+1][j+1];

             dp[i][j] = min(d,dg);
         }
     }
     return dp[0][0];
 }

 int Space_optimised(vector<vector<int>>&grid , int m){
     vector<int>dp(m,0);
     
    vector<int>cur(m,0);

    for(int j=0;j<m;j++){
        dp[j] = grid[m-1][j];
    }

     for(int i=m-2;i>=0;i--){
         for(int j=i;j>=0;j--){
             int d = grid[i][j] + dp[j];
             int dg = grid[i][j] + dp[j+1];

             cur[j] = min(d,dg);
         }
        dp = cur;
     }
    return dp[0];
 }
 
int main()
{
    int m=4;
    vector<vector<int>>grid{{1},{2,3},{3,6,7},{8,9,6,10}};

    cout<<"Minimum Path is :- (Recurssive) "<<min_path(grid,m,0,0)<<endl;
    cout<<"Minimum Path is :- (Memoization) "<<memoi(grid,m)<<endl;
    cout<<"Minimum Path is :- (Tabulation) "<<Tabulation(grid,m)<<endl;
    cout<<"Minimum Path is :- (Space Optimised) "<<Space_optimised(grid,m)<<endl;
    
 
    return 0;
}