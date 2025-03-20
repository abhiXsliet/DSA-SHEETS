// https://leetcode.com/problems/distinct-subsequences/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if (j >= n) return 1;
        if (i >= m) return 0;

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = (solve(s, t, i + 1, j + 1, dp) + solve(s, t, i + 1, j, dp));
        } else {
            return dp[i][j] = solve(s, t, i + 1, j, dp);
        }
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int top_down(string &s, string &t) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(s, t, 0, 0, dp);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int bottom_up(string &s, string &t) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i ++) {
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (s[i] == t[j]) {
                    dp[i][j] = ((long)dp[i + 1][j + 1] + dp[i + 1][j]);
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int space_optimized(string &s, string &t) {
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        curr[n] = prev[n] = 1;
    
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (s[i] == t[j]) {
                    curr[j] = ((long)prev[j + 1] + prev[j]);
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[0];
    }
public:
    int numDistinct(string s, string t) {
        m = s.length(), n = t.length();

        // return top_down(s, t);
        // return bottom_up(s, t);
        return space_optimized(s, t);
    }
};