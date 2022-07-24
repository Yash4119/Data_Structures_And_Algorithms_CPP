#include <bits/stdc++.h>
using namespace std;

int recur(int i, int j1, int j2, int r, int c, vector<vector<int>> grid)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
            {
                value = grid[i][j1] + grid[i][j2];
            }
            value += recur(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int memoi_recur(int i, int j1, int j2, int r, int c, vector<vector<int>> grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
            {
                value = grid[i][j1] + grid[i][j2];
            }
            value += memoi_recur(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int memoi(int i, int j1, int j2, int r, int c, vector<vector<int>> grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return memoi_recur(0, 0, c - 1, r, c, grid, dp);
}

int tabulation(int i, int j1, int j2, int r, int c, vector<vector<int>> grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int dj1 = 0; dj1 < c; dj1++)
    {
        for (int dj2 = 0; dj2 < c; dj2++)
        {
            if (dj1 == dj2)
                dp[r - 1][dj1][dj2] = grid[r - 1][dj1];
            else
            {
                dp[r - 1][dj1][dj2] = grid[r-1][dj1] + grid[r-1][dj2];
            }
        }
    }
    // z library

    for (int i = r - 2; i >=0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 < c and j2 + dj2 < c and j1 + dj1 >= 0 and j2 + dj2 >= 0)
                        {
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e8;
                        }
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}

int space_optimised(int i, int j1, int j2, int r, int c, vector<vector<int>> grid)
{
    vector<vector<int>>dp(c,(vector<int>(c,0)));
    vector<vector<int>>cur(c,(vector<int>(c,0)));

    for (int dj1 = 0; dj1 < c; dj1++)
    {
        for (int dj2 = 0; dj2 < c; dj2++)
        {
            if (dj1 == dj2)
                dp[dj1][dj2] = grid[r - 1][dj1];
            else
            {
                dp[dj1][dj2] = grid[r-1][dj1] + grid[r-1][dj2];
            }
        }
    }
    // z library

    for (int i = r - 2; i >=0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                        {
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 < c and j2 + dj2 < c and j1 + dj1 >= 0 and j2 + dj2 >= 0)
                        {
                            value += dp[j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            value += -1e8;
                        }
                        maxi = max(maxi, value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        dp = cur;
    }
    return dp[0][c - 1];
}

int main()
{
    vector<vector<int>> grid{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}, {1, 2, 3, 4}};
    int r = grid.size();
    int c = grid[0].size();

    cout<<"The Maximum Cherries Picked up by Alice and Bob are :- Recurrsive "<<recur(0,0,c-1,r,c,grid)<<endl;
    cout<<"The Maximum Cherries Picked up by Alice and Bob are :- Memoization "<<memoi(0,0,c-1,r,c,grid)<<endl;
    cout << "The Maximum Cherries Picked up by Alice and Bob are :- Tabulation " << tabulation(0, 0, c - 1, r, c, grid) << endl;
    cout<<"The Maximum Cherries Picked up by Alice and Bob are :- Space Optimised "<<space_optimised(0,0,c-1,r,c,grid)<<endl;

    return 0;
}