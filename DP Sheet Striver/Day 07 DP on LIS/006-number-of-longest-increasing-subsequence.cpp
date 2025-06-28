// https://leetcode.com/problems/number-of-longest-increasing-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxLis = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    }
                }
            }
            if (dp[i] > maxLis) {
                maxLis = dp[i];
            }
        }

        int cntMaxLis = 0;
        for (int i = 0; i < n; i ++) {
            if (dp[i] == maxLis) {
                cntMaxLis += count[i];
            }
        }
        return cntMaxLis;
    }
};