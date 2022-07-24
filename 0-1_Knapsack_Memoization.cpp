#include<iostream>
#include<limits>
#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
// memset(t,-1,sizeof(t));
 
int helper(int wt[],int val[],int W,int n){
    if(n==0 || W==0){
        return 0;
    }
    if(t[n][W]!=-1){
        return t[n][W];
    }

    if(wt[n-1]<=W){
        return t[n][W]= max(val[n-1]+helper(wt,val,W-wt[n-1],n-1),helper(wt,val,W,n-1));
    }
    // else if(wt[n-1]>W){
        return t[n][W] = helper(wt,val,W,n-1);
    // }
}
int knapsack(int wt[],int val[],int W,int n){
    memset(t,-1,sizeof(t));
    return helper(wt,val,W,n);
}
 
int main()
{
    int wt[4] = {1,3,4,5};
    int val[4] = {1,4,5,7};
    int W=7;

    cout<<"The maximum Profit is :- "<<knapsack(wt,val,W,4)<<endl;
 
    return 0;
}