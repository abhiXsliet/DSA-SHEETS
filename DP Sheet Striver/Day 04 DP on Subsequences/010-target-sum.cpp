// https://leetcode.com/problems/target-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int n;

    int solve_1(vector<int> &nums, int i, int target, unordered_map<string, int> &mpp) {
        if (i >= n) 
            return target == 0;

        string key = to_string(i) + "," + to_string(target);
        if (mpp.count(key))
            return mpp[key];

        int op1 = solve_1(nums, i + 1, target - nums[i], mpp);
        int op2 = solve_1(nums, i + 1, target + nums[i], mpp);

        return mpp[key] = (op1 + op2);
    }

    // TC : O(n * target)
    // SC : O(n * target)
    int top_down(vector<int> &nums, int target) {
        unordered_map<string, int> mpp;
        return solve_1(nums, 0, target, mpp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        return top_down(nums, target);
    }
};