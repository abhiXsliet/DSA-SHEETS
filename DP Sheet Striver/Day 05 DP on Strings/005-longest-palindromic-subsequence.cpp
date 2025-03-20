// https://leetcode.com/problems/longest-palindromic-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N^2)
    int LCS(string &revS, string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= revS.length() || j >= s.length())
            return 0;
            
        if (dp[i][j] != -1) return dp[i][j];
        
        int take = 0;   
        if (revS[i] == s[j]) {
            take = 1 + LCS(revS, s, i + 1, j + 1, dp);
        }
        int notTake = max(LCS(revS, s, i + 1, j, dp), LCS(revS, s, i, j + 1, dp));
        
        return dp[i][j] = max(take, notTake);
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int approach_1(string &s) {
        int n = s.length();
        string revS = s;
        reverse(begin(revS), end(revS));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return LCS(revS, s, 0, 0, dp);
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int approach_2(string &s) {
        int n = s.length();
        string revS = s;
        reverse(begin(revS), end(revS));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int take = 0;   
                if (revS[i] == s[j]) {
                    take = 1 + dp[i + 1][j + 1];
                }
                int notTake = max(dp[i + 1][j], dp[i][j + 1]);
                
                dp[i][j] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }
    
    // TC : O(N^2)
    // SC : O(N)
    int approach_3(string &s) {
        int n = s.length();
        string revS = s;
        reverse(begin(revS), end(revS));
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                int take = 0;   
                if (revS[i] == s[j]) {
                    take = 1 + prev[j + 1];
                }
                int notTake = max(prev[j], curr[j + 1]);
                
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        
        return curr[0];
    }
public:
    int longestPalinSubseq(string &s) {
        // return approach_1(s);    // Top-Down
        // return approach_2(s);    // Bottom-Up
        return approach_3(s);       // Space-Optimized
    }
};