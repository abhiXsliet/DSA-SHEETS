// https://leetcode.com/problems/delete-operation-for-two-strings/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int m, n;

    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= m || j >= n)
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int incl = 0, excl = 0;
        if (s1[i] == s2[j]) {
            incl = 1 + LCS(s1, s2, i + 1, j + 1, dp);
        } else {
            excl = max(LCS(s1, s2, i + 1, j, dp), LCS(s1, s2, i, j + 1, dp));
        }
        return dp[i][j] = max(incl, excl);
    }

    // TC : O(M * N)
    // SC : O(M * N)
    int longestCommonSubseq(string &s1, string &s2) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return LCS(s1, s2, 0, 0, dp);
    }
public:
    int minDistance(string word1, string word2) {
        m = word1.length(), n = word2.length();
        int lcs = longestCommonSubseq(word1, word2);
        return (m - lcs) + (n - lcs);
    }
};