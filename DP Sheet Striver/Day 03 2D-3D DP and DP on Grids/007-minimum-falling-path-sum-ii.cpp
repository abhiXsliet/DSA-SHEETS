// https://leetcode.com/problems/minimum-falling-path-sum-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int N;

    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if (i == N - 1) return grid[i][j];

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int ans = INT_MAX;
        for (int c = 0; c < N; c ++) {
            if (c != j) {
                ans = min(ans, grid[i][j] + solve(grid, i + 1, c, dp));
            }
        }
        return dp[i][j] = ans;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int top_down(vector<vector<int>> &grid) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MAX));
        int minPathSum = INT_MAX;
        for (int j = 0; j < N; j ++) {
            minPathSum = min(minPathSum, solve(grid, 0, j, dp));
        }
        return minPathSum;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int bottom_up(vector<vector<int>> &grid) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MAX));

        int minPathSum = INT_MAX;
        for (int i = N - 1; i >= 0; i --) {
            for (int j = N - 1; j >= 0; j--) {
                if (i == N - 1) {
                    dp[i][j] = grid[i][j];
                } else {
                    int ans = INT_MAX;
                    for (int c = 0; c < N; c ++) {
                        if (c != j) {
                            ans = min(ans, grid[i][j] + dp[i + 1][c]);
                        }
                    }
                    dp[i][j] = ans;
                }
                if (i == 0) 
                    minPathSum = min(minPathSum, dp[i][j]);
            }
        }
        return minPathSum;
    }

    // TC : O(N^2)
    // SC : O(N)
    int space_optimized(vector<vector<int>> &grid) {
        vector<int> curr(N + 1, INT_MAX), prev(N + 1, INT_MAX);

        int minPathSum = INT_MAX;
        for (int i = N - 1; i >= 0; i --) {
            for (int j = N - 1; j >= 0; j--) {
                if (i == N - 1) {
                    curr[j] = grid[i][j];
                } else {
                    int ans = INT_MAX;
                    for (int c = 0; c < N; c ++) {
                        if (c != j) {
                            ans = min(ans, grid[i][j] + prev[c]);
                        }
                    }
                    curr[j] = ans;
                }
                if (i == 0) 
                    minPathSum = min(minPathSum, curr[j]);
            }
            prev = curr;
        }
        return minPathSum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        N = grid.size();

        // return top_down(grid); 
        // return bottom_up(grid);
        return space_optimized(grid);  
    }
};