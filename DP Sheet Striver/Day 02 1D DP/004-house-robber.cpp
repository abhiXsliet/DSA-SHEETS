// https://leetcode.com/problems/house-robber/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N) 
    // Sc : O(N) visitd all 'n' states
    int solve(vector<int> &nums, int i, vector<int>& dp) {
        if (i <= 0) 
            return i == 0 ? nums[0] : 0;

        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums, i - 2, dp);
        int notT = solve(nums, i - 1, dp);

        return dp[i] = max(take, notT);
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, n - 1, dp);
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i ++) {
            int notT = nums[i] + ((i >= 2) ? dp[i - 2] : 0);
            int take = dp[i - 1];

            dp[i] = max(take, notT);
        }

        return dp[n - 1];
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> &nums) {
        int n = nums.size();
        int prev2 = 0, prev1 = nums[0];
        for (int i = 1; i < n; i ++) {
            int notT = nums[i] + ((i >= 2) ? prev2 : 0);
            int take = prev1;

            int curr = max(take, notT);
            prev2    = prev1;
            prev1    = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        // return approach_1(nums);
        // return approach_2(nums);
        return approach_3(nums);
    }
};