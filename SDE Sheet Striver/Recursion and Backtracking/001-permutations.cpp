// https://leetcode.com/problems/permutations/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N!) : There are N! permutations of the array, and we generate each one by swapping elements.
    // SC : O(N)  : Recursive Depth, because the maximum depth of the recursion tree is equal to the number of elements in the input vector
    void solve(vector<int>& nums, int index, vector<vector<int>>& res) {
        if (index >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i ++) {
            swap(nums[i], nums[index]);
            solve(nums, index + 1, res); 
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, result);
        return result;
    }
};