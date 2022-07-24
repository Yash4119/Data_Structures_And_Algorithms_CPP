#include<bits/stdc++.h>
using namespace std;
 
int frog_jump_recurr(vector<int>&heights , int n){
    if(n==0)return 0;

    int left = frog_jump_recurr(heights,n-1)+abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frog_jump_recurr(heights,n-2)+abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
}

int frog_jump_memoization(vector<int>&heights ,vector<int>&dp, int n){
    if(n==0)return 0;

if(dp[n]!=-1)return dp[n];

    int left = frog_jump_memoization(heights,dp,n-1)+abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frog_jump_memoization(heights,dp,n-2)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(left,right);
}

int helper_memoization(vector<int>&heights,int n){
    vector<int>dp(n+1,-1);
    return frog_jump_memoization(heights,dp,n);
}

int frog_jump_Tabulation(vector<int>&heights, int n){
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int fs = dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)ss = dp[i-2]+abs(heights[i]-heights[i-2]);

        dp[i] = min(fs,ss);
    }
    return dp[n];

}

int frog_jump_Space_Optimised(vector<int>&heights, int n){
    vector<int>dp(n,0);
    int prev=0;
    int prev2=0;
    for(int i=1;i<=n;i++){
        int fs = prev+abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1)ss = prev2+abs(heights[i]-heights[i-2]);

        int curr = min(fs,ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;

}

int main()
{
    vector<int>vec{10,20,10,90};

    cout<<"The Minimum Energy lost is (Recurssive Solution):- "<<frog_jump_recurr(vec,vec.size()-1)<<endl;
    cout<<"The Minimum Energy lost is (Memoization Solution):- "<<helper_memoization(vec,vec.size()-1)<<endl;
    cout<<"The Minimum Energy lost is (Tabulation Solution):- "<<frog_jump_Tabulation(vec,vec.size()-1)<<endl;
    cout<<"The Minimum Energy lost is (Space Optimised Tabulation Solution):- "<<frog_jump_Space_Optimised(vec,vec.size()-1)<<endl;
 
    return 0;
}