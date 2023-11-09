// https://leetcode.com/problems/next-permutation/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve_brute(vector<int> nums) {
        // 1. generate all permuations in sorted order recursively
        // 2. do a linear search and find the next permutation
        // 3. return 

        // TC = O(n! * n)
        // SC = O(n) -> recursive depth
    }

    void solve_optimal(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1)
            return;

        int idx = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]){
                idx = i;
                break;
            }
        }
        
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n - 1; i >= 0 ; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
public:
    void nextPermutation(vector<int>& nums) {
        // solve_brute(nums);

        // next_permutation(begin(nums), end(nums));

        return solve_optimal(nums);
    }
};