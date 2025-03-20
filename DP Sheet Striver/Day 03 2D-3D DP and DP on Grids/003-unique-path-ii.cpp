// https://leetcode.com/problems/unique-paths-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    int approach_1(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1) 
            return !grid[i][j];
        
        if (i >= m || j >= n || grid[i][j])
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = approach_1(grid, i, j + 1, dp);
        int down  = approach_1(grid, i + 1, j, dp);
        
        return dp[i][j] = (right + down);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int top_down(vector<vector<int>> &obstacleGrid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return approach_1(obstacleGrid, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int bottom_up(vector<vector<int>> &grid) {
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[m - 1][n - 1] = 1 - grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1)
                    continue;
                // If the current cell is blocked, no ways to reach it
                if (grid[i][j]) {
                    dp[i][j] = 0;
                    continue;
                }
                long right = (j + 1 < n) ? dp[i][j + 1] : 0;
                long down  = (i + 1 < m) ? dp[i + 1][j] : 0;
                dp[i][j]  = (right + down);
            }
        }
        
        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(N)
    int space_optimized(vector<vector<int>> &grid) {
        vector<long> curr(n + 1, 0), prev(n + 1, 0);
        curr[n - 1] = 1 - grid[m - 1][n - 1];

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1)
                    continue;
                // If the current cell is blocked, no ways to reach it
                if (grid[i][j]) {   // catch
                    curr[j] = 0;
                    continue;
                }

                long right = (j + 1 < n) ? curr[j + 1] : 0;
                long down  = (i + 1 < m) ? prev[j] : 0;
                curr[j]  = (right + down);
            }
            prev = curr;
        }
        
        return prev[0];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        // return top_down(obstacleGrid);
        // return bottom_up(obstacleGrid);
        return space_optimized(obstacleGrid);
    }
};