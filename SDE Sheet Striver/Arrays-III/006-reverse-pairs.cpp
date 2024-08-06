// https://leetcode.com/problems/reverse-pairs/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:   
    // TC : O(N1 + N2) ~= O(N)
    // SC : O(N1 + N2) ~= O(N)
    int merge(vector<int>& nums, int low, int mid, int high) {
        int cntReverse = 0;
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> left(n1, 0);
        vector<int> right(n2, 0);

        int i = 0, j = 0, k = low;
        while (i < n1) left[i ++]  = nums[k ++];
        while (j < n2) right[j ++] = nums[k ++];

        i = 0, j = 0, k = low;
        // Count reverse pairs
        while (i < n1 && j < n2) {
            if (left[i] > (long)2 * right[j]) {
                cntReverse += (n1 - i);
                j ++;
            } else {
                i ++;
            }
        }

        // Merge the two sorted arrays
        i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k ++] = left[i  ++];
            } else {
                nums[k ++] = right[j ++];
            }
        }

        while (i < n1) nums[k ++] = left[i ++];
        while (j < n2) nums[k ++] = right[j ++];

        return cntReverse;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int mergeSort(vector<int>& nums, int low, int high) {
        int cntRevPairs = 0;
        
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        
        cntRevPairs += mergeSort(nums, low, mid);       // O(log(N))
        cntRevPairs += mergeSort(nums, mid + 1, high);  // O(log(N))
        cntRevPairs += merge(nums, low, mid, high);     // O(N)
        
        return cntRevPairs;
    }
public:
    int reversePairs(vector<int>& nums) {
        int low  = 0;
        int high = nums.size() - 1;
        return mergeSort(nums, low, high);
    }
};