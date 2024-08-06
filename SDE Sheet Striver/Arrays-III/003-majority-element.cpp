// https://leetcode.com/problems/majority-element/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int solve(vector<int>& nums, int n) {
        int cnt         = 0;
        int majorityEle = NULL;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cnt = 1;
                majorityEle = nums[i];
            } else if( majorityEle == nums[i] ) {
                cnt++;
            } else {
                cnt--;
            }
        }
        // given that majority element always exists
        // so no need to verify the freq of majority element > n/2
        return majorityEle;
    }
public:
    int majorityElement(vector<int>& nums) {
        // Brute Force -> use Hashmap

        return solve(nums, nums.size());
    }
};