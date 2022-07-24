#include<bits/stdc++.h>
using namespace std;
 
int frog_jump_recurr(vector<int>&heights , int n,int k){
    if(n==0)return 0;
    int minsteps=INT_MAX;

    for(int i=1;i<=k;i++){
        if((n-i)>=0){
            int energy = frog_jump_recurr(heights,n-i,k)+abs(heights[n]-heights[n-i]);
            minsteps = min(minsteps,energy);
        }
    }

    return minsteps;
}

// int frog_jump_memoization(vector<int>&heights ,vector<int>&dp, int n,int k){
//     if(n==0)return 0;

// if(dp[n]!=-1)return dp[n];

//     int left = frog_jump_memoization(heights,dp,n-1)+abs(heights[n]-heights[n-1]);
//     int right = INT_MAX;
//     if(n>1){
//         right = frog_jump_memoization(heights,dp,n-2)+abs(heights[n]-heights[n-2]);
//     }
//     return dp[n]=min(left,right);
// }

// int helper_memoization(vector<int>&heights,int n,int k){
//     vector<int>dp(n+1,-1);
//     return frog_jump_memoization(heights,dp,n);
// }

int frog_jump_Tabulation(vector<int>&heights, int n, int k){
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int minsteps=INT_MAX;
        for(int j=1;j<=k;j++){
            int energy;
            if(i-j>=0)energy = dp[i-j]+abs(heights[i]-heights[i-j]);
            minsteps = min(minsteps,energy);
        }
    dp[i] = minsteps;

    }
    return dp[n];

}

int main()
{
    vector<int>vec{40,20,10,90};

    cout<<"The Minimum Energy lost is (Recurssive Solution):- "<<frog_jump_recurr(vec,vec.size()-1,3)<<endl;
    // cout<<"The Minimum Energy lost is (Memoization Solution):- "<<helper_memoization(vec,vec.size()-1,4)<<endl;
    cout<<"The Minimum Energy lost is (Tabulation Solution):- "<<frog_jump_Tabulation(vec,vec.size()-1,3)<<endl;
 
    return 0;
}