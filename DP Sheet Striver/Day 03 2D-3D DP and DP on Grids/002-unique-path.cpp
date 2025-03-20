// https://leetcode.com/problems/unique-paths/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M * N)
    // SC : O(M * N)
    int solve(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1)
            return 1;

        if (i >= m || j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(m, n, i, j + 1, dp); 
        int down  = solve(m, n, i + 1, j, dp);

        return dp[i][j] = (right + down);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int top_down(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int bottom_up(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1) 
                    continue;
                int right = (j + 1 < n) ? dp[i][j + 1] : 0; 
                int down  = (i + 1 < m) ? dp[i + 1][j] : 0;
                dp[i][j] = (right + down);
            }
        }

        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int space_optimized(int m, int n) {
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        curr[n - 1] = 1;

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (i == m - 1 && j == n - 1) 
                    continue;
                int right = (j + 1 < n) ? curr[j + 1] : 0; 
                int down  = (i + 1 < m) ? prev[j] : 0;
                curr[j] = (right + down);
            }
            prev = curr;
        }

        return curr[0];
    }
public:
    int uniquePaths(int m, int n) {
        // return top_down(m, n);
        // return bottom_up(m, n); 
        return space_optimized(m, n); 
    }
};