// https://leetcode.com/problems/single-element-in-a-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(log(N))
    // SC : O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        if (nums[0] != nums[1]) 
            return nums[0];
        if (nums[n - 1] != nums[n - 2]) 
            return nums[n - 1];

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid + 1 < n && mid - 1 >= 0 && nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            
            if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                if ((mid - low) % 2 == 0) {
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else {
                if ((high - mid) % 2 == 0) {
                    high = mid - 2;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};