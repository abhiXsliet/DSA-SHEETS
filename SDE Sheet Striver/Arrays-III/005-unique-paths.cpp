// https://leetcode.com/problems/unique-paths/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * M)
    // SC = O(N * M)
    int mem(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) return 1;
        if (i == m     || j == n)     return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int right = mem(i + 1, j, m, n, dp);
        int down  = mem(i, j + 1, m, n, dp);

        return dp[i][j] = down + right;
    }

    // TC = O(N * M)
    // SC = O(N * M)
    int tab(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = 1;
        }

        for (int i = 0; i < n; i++) {
            dp[m - 1][i] = 1;
        }

        for (int i = m - 2; i >= 0; i --) {
            for (int j = n - 2; j >= 0; j --) {
                
                int right = dp[i + 1][j];
                int down  = dp[i][j + 1];
                dp[i][j]  = down + right;

            }
        }
        return dp[0][0];
    }

    // TC = O(N * M)
    // SC = O(N)
    int so(int m, int n) {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int i = 0; i < m; i ++) {
            curr[n - 1] = 1;
        }
        for (int i = 0; i < n; i ++) {
            next[i] = 1;
        }

        for (int i = m - 2; i >= 0; i --) {
            for (int j = n - 2; j >= 0; j --) {
                
                int right = next[j];
                int down  = curr[j + 1];
                curr[j]   = down + right;
            
            }
            next = curr;
        }
        return next[0];
    }

    // TC : O(M)
    // SC : O(1)
    int optimal(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        long double res = 1;

        // NCr
        for (int i = 1; i <= r; i ++) {
            // res = res * (N - r + i) / i;
            
            res *= (N - (i - 1));
            res /= i;
            // res = res * (N - (i - 1)) / i;  // one liner
        }
        return (int)(res);
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return mem(0, 0, m, n, dp);

        // return tab(m, n);

        // return so(m, n);

        return optimal(m, n);
    }
};