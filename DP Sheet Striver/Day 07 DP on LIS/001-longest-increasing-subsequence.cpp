// https://leetcode.com/problems/longest-increasing-subsequence/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    
    int solve(vector<int> &nums, int curr, int prev, vector<vector<int>> & dp) {
        if (curr >= n) return 0;

        if (prev != -1 && dp[curr][prev] != -1)
            return dp[curr][prev];

        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solve(nums, curr + 1, curr, dp);
        }
        int notT = solve(nums, curr + 1, prev, dp);

        int ans = max(take, notT);
        if (prev != -1) {
            dp[curr][prev] = ans;
        }
        return ans;
    }

    // TC : O(n * n)
    // SC : O(n * n)
    int top_down(vector<int> &nums) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }

    // TC : O(n * n)
    // SC : O(n * n)
    int bottom_up(vector<int> &nums) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int curr = n - 1; curr >= 0; curr --) {
            for (int prev = curr - 1; prev >= -1; prev --) {
                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    take = 1 + dp[curr + 1][curr + 1];
                }
                int notT = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, notT);
            }
        }
        return dp[0][0];
    }

    // TC : O(n * n)
    // SC : O(n)
    int space_optimized(vector<int> &nums) {
        vector<int> currRow(n + 1, 0), prevRow(n + 1, 0);
        for (int curr = n - 1; curr >= 0; curr --) {
            for (int prev = curr - 1; prev >= -1; prev --) {
                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev]) {
                    take = 1 + prevRow[curr + 1];
                }
                int notT = prevRow[prev + 1];

                currRow[prev + 1] = max(take, notT);
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }

    // TC : O(n*log(n))
    // SC : O(n)
    int optimal(vector<int> &nums) {
        int n = nums.size();
        vector<int> store;
        for (int i = 0; i < n; i ++) {
            if (store.empty() || nums[i] > store.back()) {
                store.push_back(nums[i]);
            } else {
                int idx = lower_bound(begin(store), end(store), nums[i]) - begin(store);
                store[idx] = nums[i];
            }
        }
        return store.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        // return top_down(nums);
        // return bottom_up(nums);
        // return space_optimized(nums);
        return optimal(nums);
    }
};