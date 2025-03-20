// https://leetcode.com/problems/partition-equal-subset-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;

    bool solve_2(vector<int> &nums, int i, int curr, int tar, vector<vector<int>> &dp) {
        if (i >= n || curr >= tar) 
            return curr == tar;

        if (dp[i][curr] != -1)
            return dp[i][curr];

        bool take = solve_2(nums, i + 1, curr + nums[i], tar, dp);
        bool notT = solve_2(nums, i + 1, curr, tar, dp);

        return dp[i][curr] = (take | notT);
    }

    bool solve_1(vector<int> &nums, int i, int curr, int tot, vector<vector<vector<int>>> &dp) {
        if (curr == tot) return true;
        if (i >= n) return false;

        if (dp[i][curr][tot] != -1)
            return dp[i][curr][tot];

        bool take = solve_1(nums, i + 1, curr + nums[i], tot - nums[i], dp);
        bool notT = solve_1(nums, i + 1, curr, tot, dp);

        return dp[i][curr][tot] = (take | notT);
    }

    // TC : O(N * tot * tot) where tot = sum of all elements of array
    // SC : O(N * tot * tot)
    bool top_down_1(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(tot + 1, vector<int>(tot + 1,  -1)));
        return solve_1(nums, 0, 0, tot, dp);
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(N * target)
    bool top_down_2(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1,  -1));
        return solve_2(nums, 0, 0, target, dp);
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(N * target)
    bool bottom_up(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1,  0));

        for (int i = 0; i <= n; i ++) {
            dp[i][target] = 1;
        }

        for (int i = n - 1; i >= 0; i --) {
            for (int curr = target; curr >= 0; curr --) {
                bool take = curr + nums[i] <= target ? dp[i + 1][curr + nums[i]] : 0;
                bool notT = dp[i + 1][curr];
                dp[i][curr] = (take | notT);
            }
        }

        return dp[0][0];
    }

    // TC : O(N * target) Where target = sum of all elements / 2
    // SC : O(target)
    bool space_optimized(vector<int> &nums) {
        int tot = accumulate(begin(nums), end(nums), 0);
        if (tot % 2) return false;
        int target = tot / 2;
        vector<int> currRow(target + 1,  0), prevRow(target + 1, 0);

        currRow[target] = prevRow[target] = 1;

        for (int i = n - 1; i >= 0; i --) {
            for (int curr = target; curr >= 0; curr --) {
                bool take = curr + nums[i] <= target ? prevRow[curr + nums[i]] : 0;
                bool notT = prevRow[curr];
                currRow[curr] = (take | notT);
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        // return top_down_1(nums);     // MLE : 3D DP
        // return top_down_2(nums);     // 2D DP
        // return bottom_up(nums);
        return space_optimized(nums);
    }
};