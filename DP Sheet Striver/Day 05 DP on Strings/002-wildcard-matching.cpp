// https://leetcode.com/problems/wildcard-matching/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    bool solve(string s, string p, int i, int j, vector<vector<int>> &dp) {
        if (i == m && j == n)   
            return true;

        if (i < m && j == n)
            return false;

        if (i == m && j < n) {
            for (int k = n - 1; k >= j; k --) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1) 
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            return dp[i][j] = (solve(s, p, i, j + 1, dp) || solve(s, p, i + 1, j, dp));
        }

        return dp[i][j] = false;
    }
    
    // TC : O(m * n)
    // SC : O(m * n)
    bool top_down(string s, string p) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(s, p, 0, 0, dp);
    }

    // TC : O(m * n)
    // SC : O(m * n)
    bool bottom_up(string s, string p) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[m][n] = 1;

        for (int j = n - 1; j >= 0; j --) { // base case : when str is over but patt is remaining
            bool flag = 1;  // Assume all remaining characters are '*'
            for (int k = n - 1; k >= j; k --) { // Check from index j to the end of the pattern
                if (p[k] != '*') {  
                    flag = 0;   // If any character is not '*', set flag to false
                    break;
                }
            }
            dp[m][j] = flag;    // dp[m][j] is true if all remaining characters are '*'
        }

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = (dp[i][j + 1] || dp[i + 1][j]);
                }else 
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }

    // TC : O(m * n)
    // SC : O(n)
    bool space_optimized(string s, string p) {
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        prev[n] = 1;

        for (int j = n - 1; j >= 0; j --) { // base case : when str is over but patt is remaining
            bool flag = 1;  // Assume all remaining characters are '*'
            for (int k = n - 1; k >= j; k --) { // Check from index j to the end of the pattern
                if (p[k] != '*') {  
                    flag = 0;   // If any character is not '*', set flag to false
                    break;
                }
            }
            prev[j] = flag;    // dp[m][j] is true if all remaining characters are '*'
        }

        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                
                if (s[i] == p[j] || p[j] == '?') {
                    curr[j] = prev[j + 1];
                } else if (p[j] == '*') {
                    curr[j] = (curr[j + 1] || prev[j]);
                }else 
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[0];
    }
public:
    bool isMatch(string s, string p) {
        m = s.length(), n = p.length();

        // return top_down(s, p);
        // return bottom_up(s, p);
        return space_optimized(s, p);
    }
};