// https://leetcode.com/problems/majority-element-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    vector<int> brute(vector<int>& nums, int n) {
        vector<int> ans;

        int m = (int)(n / 3) + 1;

        unordered_map<int, int>mpp;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;

            if (mpp[nums[i]] == m) 
                ans.push_back(nums[i]);
            if (ans.size() == 2)
                break;
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(vector<int>& nums, int n) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if(cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            } 
            else if(nums[i] == ele1) cnt1 ++;
            else if(nums[i] == ele2) cnt2 ++;
            else {
                cnt1 --;
                cnt2 --;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(ele1 == nums[i]) cnt1 ++;
            if(ele2 == nums[i]) cnt2 ++;
        }

        int m = (int)(n / 3) + 1;   // +1 to get the floor value
        vector<int> ans;

        // Atmost 2-Elements can occur more than ⌊ n/3 ⌋ in an array of length n
        if(cnt1 >= m) ans.push_back(ele1);
        if(cnt2 >= m) ans.push_back(ele2);

        return ans;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        // return brute(nums, nums.size());

        return optimal(nums, nums.size());
    }
};