// https://leetcode.com/problems/two-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> solve(vector<int>& nums, int tar) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i < n; i++) {
            int req = tar - nums[i];
            if(mpp.find(req) != mpp.end()) {
                return {mpp[req], i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute : Use 2-Loops

        return solve(nums, target);
    }
};