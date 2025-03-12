// https://leetcode.com/problems/next-greater-element-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(M + N)
    // SC : O(M + N)
    vector<int> approach_1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < m; i ++) {
            mpp[nums1[i]] = i;
        }
        stack<int> stk;
        vector<int> result(m, -1);
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                if (mpp.count(nums2[stk.top()])) {
                    result[mpp[nums2[stk.top()]]] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return approach_1(nums1, nums2);
    }
};