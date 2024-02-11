// https://leetcode.com/problems/search-in-rotated-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve_brute(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }

    // TC : O(log(N))
    // SC : O(1)
    int solve_optimal(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[low] <= nums[mid]) { // left part is sorted
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { // right part is sorted
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        // return solve_brute(nums, target);

        return solve_optimal(nums, target);
    }
};