#include<iostream>
#include<limits>
#include<bits/stdc++.h>
using namespace std;

// int t[1001][1001];

int knapsack(int wt[],int val[],int W,int n){
    // Code for Initialization
    int t[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][W];

}
 
int main()
{
    int wt[4] = {1,3,4,5};
    int val[4] = {1,4,5,7};
    int W=7;

    cout<<"The maximum Profit is :- "<<knapsack(wt,val,W,4)<<endl;
 
    return 0;
}