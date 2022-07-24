#include<bits/stdc++.h>
using namespace std;
 
 int Max_Subsequence(vector<int>&vec,int n){
     if(n==0)return vec[n];
     if(n<0)return 0;

     int pick = vec[n] + Max_Subsequence(vec,n-2);
     int not_pick = 0 + Max_Subsequence(vec,n-1);

    return max(pick,not_pick);
 }

  int Max_Subsequence_Memoization(vector<int>&vec,vector<int>&dp,int n){
     if(n==0)return vec[n];
     if(n<0)return 0;
     
    if(dp[n]!=-1)return dp[n];

     int pick = vec[n] + Max_Subsequence(vec,n-2);
     int not_pick = 0 + Max_Subsequence(vec,n-1);

    return dp[n]=max(pick,not_pick);
 }

 int helper1(vector<int>vec,int n){
     vector<int>dp(n+1,-1);
     return Max_Subsequence_Memoization(vec,dp,n);
 }

 int Tabulation(vector<int>vec,int n){
     vector<int>dp(n+1,-1);

    dp[0] = vec[0];

    for(int i=1;i<=n;i++){
        int take = vec[i];
        if(i>1){
            take+=dp[i-2];
        }

        int dont_take = 0 + dp[i-1];

        dp[i] = max(take,dont_take);
    }

     return dp[n];
 }
 
 int Tabulation_Space_Optimised(vector<int>vec,int n){

    int prev = vec[0];
    int prev2=0;

    for(int i=1;i<=n;i++){
        int take = vec[i];
        if(i>1){
            take+=prev2;
        }

        int dont_take = 0 + prev;

        int curr = max(take,dont_take);
        prev2 = prev;
        prev = curr;
    }

     return prev;
 }
 
int main()
{
    vector<int>vec{2,4,1,6,56,23,2,123,6,8,9};

    cout<<"Maximum sum among the Subsequences is (Recurssive Code):- "<<Max_Subsequence(vec,vec.size()-1)<<endl;
    cout<<"Maximum sum among the Subsequences is (Memoization Code):- "<<helper1(vec,vec.size()-1)<<endl;
    cout<<"Maximum sum among the Subsequences is (Tabulation Code):- "<<Tabulation(vec,vec.size()-1)<<endl;
    cout<<"Maximum sum among the Subsequences is (Tabulation Space Optimised Code):- "<<Tabulation_Space_Optimised(vec,vec.size()-1)<<endl;
 
    return 0;
}