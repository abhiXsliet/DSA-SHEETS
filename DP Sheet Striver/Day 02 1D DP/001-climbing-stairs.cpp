// https://leetcode.com/problems/climbing-stairs/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(int n, vector<int> &dp) {
        if (n <= 0) return n == 0 ? 1 : 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = approach_1(n - 1, dp) + approach_1(n - 2, dp);
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(int n) {
        int curr = 1, prev = 1;
        int ans = 1;
        for (int i = 2; i <= n; i ++) {
            ans  = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        // return approach_1(n, dp);

        // return approach_2(n);
        return approach_3(n);
    }
};