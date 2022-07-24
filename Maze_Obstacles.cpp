#include <bits/stdc++.h>

using namespace std;

//Code For Recurrssive Approach

int Unique(int m,int n,vector<vector<int>>mat){
    if(m>=0 and n>=0 and mat[m][n]==-1)return 0;
    if(m==0 and n==0)return 1;
    if(m<0 || n<0)return 0;
    
    int up = Unique(m-1,n,mat);
    int left = Unique(m,n-1,mat);
    
    return up+left;
}

//Code For Memoization Approach

int Unique_memoi(int m,int n,vector<vector<int>>&dp,vector<vector<int>>mat){
    if(m>=0 and n>=0 and mat[m][n]==-1)return 0;
    if(m==0 and n==0)return 1;
    if(m<0 || n<0)return 0;
    
    if(dp[m][n]!=-1)return dp[m][n];
    
    int up = Unique_memoi(m-1,n,dp,mat);
    int left = Unique_memoi(m,n-1,dp,mat);
    
    return dp[m][n]=up+left;
}
int memoi(int m,int n,vector<vector<int>>mat){
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return Unique_memoi(m,n,dp,mat);
}

//Code For Tabulation Approach

int Tabulation(int m,int n,vector<vector<int>>mat){
    int dp[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1)dp[i][j]=0;
            else if(i==0 and j==0)dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

//Code For Tabulation(Space Optimised) Approach

int Tabulation_Space(int m,int n,vector<vector<int>>mat){
    vector<int>prev(n,0);
    
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1)prev[j]=0;
            else if(i==0 and j==0)temp[j]=1;
            else{
                int up=0,left=0;
                if(i>0)up = prev[j];
                if(j>0)left = temp[j-1];
                temp[j] = up+left;
            }
        }
        prev = temp;
    }
    return prev[n-1];
}

int main()
{
    int m=5,n=4;
    vector<vector<int>>mat(m,vector<int>(4,0));
    mat[2][1] = mat[1][2] = -1;
    cout<<"Unique Ways For grid Of size (5 X 4) is :- (Recurssive) "<<Unique(m-1,n-1,mat)<<endl;
    cout<<"Unique Ways For grid Of size (5 X 4) is :- (Memoization) "<<memoi(m-1,n-1,mat)<<endl;
    cout<<"Unique Ways For grid Of size (5 X 4) is :- (Tabulation) "<<Tabulation(m,n,mat)<<endl;
    cout<<"Unique Ways For grid Of size (5 X 4) is :- (Tabulation Space Optimised) "<<Tabulation_Space(m,n,mat)<<endl;

    return 0;
}
