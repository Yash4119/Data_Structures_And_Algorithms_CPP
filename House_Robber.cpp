#include<bits/stdc++.h>
using namespace std;
 
 int House_robber(vector<int>&vec,int n){
     if(n==0)return vec[n];
     if(n<0)return 0;

     if(n>1)int pick = vec[n] + House_robber(vec,n-2);
     int not_pick = 0 + House_robber(vec,n-1);

    return max(pick,not_pick);
 }
  int House_robber_recurr(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp;
        vector<int>temp1;
        for(int i=0;i<n;i++){
            if(i!=0)temp.push_back(nums[i]);
            if(i!=n-1)temp1.push_back(nums[i]);
        }
        return max(House_robber(temp,n),House_robber(temp1,n));
    }

  int House_robber_Memoization(vector<int>&vec,vector<int>&dp,int n){
     if(n==0)return vec[n];
     if(n<0)return 0;
     
    if(dp[n]!=-1)return dp[n];

     int pick = vec[n] + House_robber_Memoization(vec,dp,n-2);
     int not_pick = 0 + House_robber_Memoization(vec,dp,n-1);

    return dp[n]=max(pick,not_pick);
 }

    int House_robber_memoi(vector<int>& nums) {
         int n = nums.size();
        vector<int>dp(n+1,-1);
       
        if(n==1)return nums[0];
        vector<int>temp;
        vector<int>temp1;
        for(int i=0;i<n;i++){
            if(i!=0)temp.push_back(nums[i]);
            if(i!=n-1)temp1.push_back(nums[i]);
        }
        return max(House_robber_Memoization(temp,dp,n),House_robber_Memoization(temp1,dp,n));
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
 int House_robber_Tab(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp;
        vector<int>temp1;
        for(int i=0;i<n;i++){
            if(i!=0)temp.push_back(nums[i]);
            if(i!=n-1)temp1.push_back(nums[i]);
        }
        return max(Tabulation(temp,n-1),Tabulation(temp1,n-1));
    }
 
  int Tabulation_Space_Optimised(vector<int>val){
        int n = val.size();
        int prev2=0;
        int prev = val[0];
        
        for(int i=1;i<n;i++){
            int pick = val[i];
            if(i>1)pick+=prev2;
            
            int not_pick = 0+prev;
            int curr = max(pick,not_pick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
    int House_robber_Space(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>temp;
        vector<int>temp1;
        for(int i=0;i<n;i++){
            if(i!=0)temp.push_back(nums[i]);
            if(i!=n-1)temp1.push_back(nums[i]);
        }
        return max(Tabulation_Space_Optimised(temp),Tabulation_Space_Optimised(temp1));
    }
 
int main()
{
    vector<int>vec{2,4,1,6,56,23,2,123,6,8,9};

    cout<<"Maximum sum among the Subsequences is (Recurssive Code):- "<<House_robber_recurr(vec)<<endl;
    cout<<"Maximum sum among the Subsequences is (Memoization Code):- "<<House_robber_memoi(vec)<<endl;
    cout<<"Maximum sum among the Subsequences is (Tabulation Code):- "<<House_robber_Tab(vec)<<endl;
    cout<<"Maximum sum among the Subsequences is (Tabulation Space Optimised Code):- "<<House_robber_Space(vec)<<endl;
 
    return 0;
}