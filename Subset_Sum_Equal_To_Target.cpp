#include <bits/stdc++.h>
using namespace std;

bool recur(vector<int> arr, int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return (arr[0] == target);

    bool not_take = recur(arr, n - 1, target);
    bool take = false;
    if (arr[n] <= target)
    {
        take = recur(arr, n - 1, target - arr[n]);
    }

    return not_take | take;
}

bool recur_memoi(vector<int> arr, vector<vector<int>> &dp, int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return (arr[0] == target);

    if (dp[n][target] != -1)
        return dp[n][target];

    bool not_take = recur_memoi(arr, dp, n - 1, target);
    bool take = false;
    if (arr[n] <= target)
    {
        take = recur_memoi(arr, dp, n - 1, target - arr[n]);
    }

    return dp[n][target] = not_take | take;
}

bool memoi(vector<int> arr, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return recur_memoi(arr, dp, n - 1, target);
}

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

bool space_optimised(vector<int> arr, int n, int target)
{
    vector<bool> prev(target + 1, 0);
    vector<bool> cur(target + 1, 0);

    prev[0] = true;
    cur[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool not_take = prev[k];
            bool take = false;
            if (arr[i] <= k)
            {
                take = prev[k - arr[i]];
            }

            cur[k] = not_take | take;
        }
        prev = cur;
    }
    return prev[target];
}

int main()
{
    vector<int> arr{2, 7, 11, 1, 13, 4, 8};

    if (recur(arr, 6, 17))
        cout << " (Recurssion) Found" << endl;
    else
        cout << " (Recurssion) Not Found" << endl;

    if (memoi(arr, 7, 90))
        cout << " (Memoization) Found" << endl;
    else
        cout << " (Memoization) Not Found" << endl;

    if (tabulation(arr, 7, 17))
        cout << " (Tabulation) Found" << endl;
    else
        cout << " (Tabulation) Not Found" << endl;

    if (space_optimised(arr, 7, 97))
        cout << " (Space Optimisation) Found" << endl;
    else
        cout << " (Space Optimisation) Not Found" << endl;

    return 0;
}