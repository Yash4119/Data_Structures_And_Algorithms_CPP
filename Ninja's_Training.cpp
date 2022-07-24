#include<bits/stdc++.h>
using namespace std;
 
 //Code For the Recurrssive Approach
 
 int points_recurr(vector<vector<int>>&points,int n,int last){
     if(n==0){
         int maxi=0;
         for(int i=0;i<3;i++){
             if(i!=last){
                 maxi = max(maxi,points[0][i]);
             }
         }
         return maxi;
     }

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[n][i]+points_recurr(points,n-1,i);
            maxi = max(point,maxi);
        }
    }
    return maxi;
    }
    
    // code for memoization Approach
    
    int points_memoi(vector<vector<int>>&points,vector<vector<int>>&dp,int n,int last){
     if(n==0){
         int maxi=0;
         for(int i=0;i<3;i++){
             if(i!=last){
                 maxi = max(maxi,points[0][i]);
             }
         }
         return maxi;
     }
    if(dp[n][last]!=-1)return dp[n][last];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[n][i]+points_memoi(points,dp,n-1,i);
            maxi = max(point,maxi);
        }
    }
    return dp[n][last]=maxi;
    }
    
    int memoi(vector<vector<int>>&points,int n,int last){
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        return points_memoi(points,dp,n,last);
    }
    
    // Tabulation that is the Bottom Up Approach
    
    int Tabulation(vector<vector<int>>&points,int n){
        vector<vector<int>>dp(n,vector<int>(4,0));
        
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][1],points[0][0]);
        dp[0][3] = max(points[0][1],max(points[0][0],points[0][2]));
        
        for(int day = 1;day<n;day++){
            for(int last=0;last<4;last++){
                // dp[day][last] = 0;
                
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int point = points[day][i] + dp[day-1][i];
                        dp[day][last] = max(dp[day][last] ,point );
                    }
                }
                
            }
        }
        
        return dp[n-1][3];
    }
    
    // Space Optimised Solution for the Tabulation that is the Bottom Up Approach
    
    int Tabulation_Space(vector<vector<int>>&points,int n){
        vector<int>dp(4,0);
        
        dp[0] = max(points[0][1],points[0][2]);
        dp[1] = max(points[0][0],points[0][2]);
        dp[2] = max(points[0][1],points[0][0]);
        dp[3] = max(points[0][1],max(points[0][0],points[0][2]));
        
        for(int day = 1;day<n;day++){
            vector<int>temp(4,0);
            for(int last=0;last<4;last++){
                
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int point = points[day][i] + dp[i];
                        temp[last] = max(temp[last] ,point );
                    }
                }
                
            }
            dp=temp;
        }
        
        return dp[3];
    }
 
int main()
{
    vector<vector<int>>points{{4,1,8},{2,0,5},{6,1,3},{3,7,4},{1,2,3},{3,7,4},{1,6,3},{9,5,7},{0,4,1}};
    cout<<"Max training points are (Recurrssive):- "<<points_recurr(points,points.size()-1,3)<<endl;
    cout<<"Max training points are (Memoization):- "<<points_recurr(points,points.size()-1,3)<<endl;
    cout<<"Max training points are (Tabulation):- "<<Tabulation(points,points.size())<<endl;
    cout<<"Max training points are (Tabulation):- "<<Tabulation_Space(points,points.size())<<endl;
    
 
    return 0;
}