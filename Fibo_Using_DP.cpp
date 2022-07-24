#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int fibo(int n,vector<int>&dp){
    if(n<=1)return n;

    if(dp[n]!=-1)return dp[n];

    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}

int fibo_space_optimised(int n){
    int prev2=0;
    int prev=1;

    for(int i=2;i<=n;i++){
        int ans = prev2+prev;
        prev2 = prev;
        prev = ans;
    }
    return prev;
}
 
int Climbing(int s){
    vector<int>dp(s+2,-1);
    return fibo(s+1,dp);
}
// int Climbing(int s){
//     return fibo_space_optimised(s+1);
// }

int main()
{
    int n;
    cout<<"enter the term that you want from the Fibonacci series :- ";
    cin>>n;
    cout<<endl;

    
    cout<<"The "<<n<<"the number of Distinct Ways is :- "<<Climbing(n)<<endl;
    // cout<<"The "<<n<<"the number of Distinct Ways Using Space Optimisation is :- "<<Climbing(n)<<endl;
 
    return 0;
}