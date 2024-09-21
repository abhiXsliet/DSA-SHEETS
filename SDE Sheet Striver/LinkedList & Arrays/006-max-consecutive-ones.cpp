// https://leetcode.com/problems/max-consecutive-ones/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxConsecOne = 0;
        int cntOne = 0;
        for (int &num : nums) {
            if (num == 1) {
                cntOne ++;
                maxConsecOne = max(maxConsecOne, cntOne);
            } else {
                cntOne = 0;
            }
        }
        return maxConsecOne;
    }
};