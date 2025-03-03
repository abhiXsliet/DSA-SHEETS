// https://leetcode.com/problems/median-of-two-sorted-arrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M + N)
    // SC : O(1)
    double approach_1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int size = m + n;

        int idx1 = size / 2;        // index for odd no. of elements
        int idx2 = (size - 1) / 2;  // index for even no. of elements
        int ele1 = -1, ele2 = -1;

        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                if (k == idx1) ele1 = nums1[i];
                if (k == idx2) ele2 = nums1[i];
                i ++;
            } else {
                if (k == idx1) ele1 = nums2[j];
                if (k == idx2) ele2 = nums2[j];  
                j ++;
            }
            k ++;
        }
        while (i < m) {
            if (k == idx1) ele1 = nums1[i];
            if (k == idx2) ele2 = nums1[i];
            i ++;
            k ++;
        }
        while (j < n) {
            if (k == idx1) ele1 = nums2[j];
            if (k == idx2) ele2 = nums2[j];
            j ++;
            k ++;
        }
        if (size % 2) {
            return ele1;
        } 
        return (double)(ele1 + ele2) / 2.0;
    }

    // TC : O(log(min(m, n)))
    // SC : O(1)
    double approach_2(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {    // Applying BS on shorter array
            return findMedianSortedArrays(nums2, nums1);
        }
        int size = m + n;
        int median = (m + n + 1) / 2;   // required symmetry
        int low = 0, high = m;  // choosing b/w 0 and m no. of elements from array-1
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = (median - mid1);

            int l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1 - 1];
            int l2 = mid2 - 1 < 0 ? INT_MIN : nums2[mid2 - 1];
            int r1 = mid1 >= m    ? INT_MAX : nums1[mid1];
            int r2 = mid2 >= n    ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (size % 2) {
                    return max(l1, l2);
                }
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2) {  // we took more elements from array-1, so reduce it
                high = mid1 - 1;
            } else { // (l2 > r1) : we require to choose more elements from array-1, so increase
                low = mid1 + 1;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return approach_1(nums1, nums2); // Using three pointers, i, j and k

        // return approach_2(nums1, nums2); // Optimal : BS on shorter array
    }
};