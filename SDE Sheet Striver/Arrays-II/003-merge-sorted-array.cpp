// https://leetcode.com/problems/merge-sorted-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N + M)
    // SC : O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i --;
            } else if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j --;
            } 
            k --;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j --;
            k --;
        }
    }
};