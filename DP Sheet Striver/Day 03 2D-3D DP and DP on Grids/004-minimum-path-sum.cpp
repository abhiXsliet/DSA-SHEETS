// https://leetcode.com/problems/minimum-path-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (i >= m || j >= n) 
            return INT_MAX;

        if (dp[i][j] != -1) 
            return dp[i][j];

        int right = solve(grid, i, j + 1, dp);
        int down  = solve(grid, i + 1, j, dp);

        return dp[i][j] = (grid[i][j] + min(right, down));
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int top_down(vector<vector<int>> &grid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(grid, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int bottom_up(vector<vector<int>> &grid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1)
                    continue;

                int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                int down  = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;
                dp[i][j]  = grid[i][j] + min(right, down);
            }
        }

        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(N)
    int space_optimized(vector<vector<int>> &grid) {
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        curr[n - 1] = grid[m - 1][n - 1];
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1)
                    continue;

                int right = (j + 1 < n) ? curr[j + 1] : INT_MAX;
                int down  = (i + 1 < m) ? prev[j] : INT_MAX;
                curr[j]  = grid[i][j] + min(right, down);
            }
            prev = curr;
        }

        return curr[0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        // return top_down(grid);
        // return bottom_up(grid);
        return space_optimized(grid);
    }
};