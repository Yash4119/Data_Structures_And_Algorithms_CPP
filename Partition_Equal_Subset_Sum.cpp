#include<bits/stdc++.h>
using namespace std;
 
bool tabulation(vector<int> arr, int n, int target)
{
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool not_take = dp[i - 1][k];
            bool take = false;
            if (arr[i] <= k)
            {
                take = dp[i - 1][k - arr[i]];
            }

            dp[i][k] = not_take | take;
        }
    }
    return dp[n - 1][target];
}

bool equal_partition(int n,vector<int>arr){
    int tot_sum=0;
    for(int i=0;i<n;i++)tot_sum += arr[i];

    if(tot_sum%2) return false;

    return tabulation(arr,n,tot_sum/2);
}

 
int main()
{
    vector<int>arr{2,3,1,3,3,4,5};

    if(equal_partition(7,arr)){
        cout<<"Is Possible"<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
 
    return 0;
}