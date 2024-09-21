// https://leetcode.com/problems/remove-duplicates-from-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& nums) {
        vector<int> freq(201, 0);
        for (int& num : nums) {
            freq[num + 100] ++;
        }
        nums.clear();
        int cnt = 0;
        for (int i = 0; i < 201; i ++) {
            if (freq[i] > 0) {
                cnt ++;
                nums.push_back(i - 100);
            }
        }
        return cnt;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i + 1;
        while (j < n) {
            if (nums[i] != nums[j]) {
                i ++;
                nums[i] = nums[j];
            } 
            j ++;
        }
        return (i + 1);
    }
public:
    int removeDuplicates(vector<int>& nums) {
        // return approach_1(nums);    // BRUTE

        return approach_2(nums);
    }
};