// https://leetcode.com/problems/house-robber-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solve(vector<int> &nums, int n, int i, int limit, vector<vector<int>>& dp) {
        if (i <= limit) 
            return i == limit ? nums[i] : 0;

        if (dp[i][limit] != -1) return dp[i][limit];

        int take = nums[i] + solve(nums, n, i - 2, limit, dp);
        int notT = solve(nums, n, i - 1, limit, dp);

        return dp[i][limit] = max(take, notT);
    }

    // TC : O(N*2)
    // SC : O(N*2)
    int approach_1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // skip first house & take till last house OR skip last house and take till first house
        return max(solve(nums, n, n - 1, 1, dp), solve(nums, n, n - 2, 0, dp));
    }

    // TC : O(N*2)
    // SC : O(N*2)
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        dp[0][0] = nums[0]; // considering till 1st house from n - 2
        dp[1][1] = nums[1]; // considering till 2nd house from n - 1 (skip 1st house)

        for (int i = 1; i < n; i ++) {
            for (int limit = 0; limit <= 1; limit ++) {
                int take = nums[i] + ((i >= 2) ? dp[i - 2][limit] : 0);
                int notT = dp[i - 1][limit];

                dp[i][limit] = max(take, notT);
            }
        }

        return max(dp[n - 1][1], dp[n - 2][0]);
    }

    // TC : O(N*2)
    // SC : O(N*2)
    int approach_3(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        auto calc = [&](int start, int end) {
            int prev2 = 0, prev1 = 0;
            for (int i = start; i <= end; i ++) {
                int take = nums[i] + prev2; // take curr house + 2-houses before
                int notT = prev1;

                int curr = max(take, notT);
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };
        // Compute max by either including 1st house (skip last) or including last (skip first)
        return max(calc(1, n - 1), calc(0, n - 2));
    }
public:
    int rob(vector<int>& nums) {
        // return approach_1(nums);
        // return approach_2(nums);
        return approach_3(nums);
    }
};