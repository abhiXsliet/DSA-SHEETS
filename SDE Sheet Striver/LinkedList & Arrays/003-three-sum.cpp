// https://leetcode.com/problems/3sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2)
    // SC : O(N)
    vector<vector<int>> better(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i ++) {
            unordered_set<int> seen;
            for (int j = i + 1; j < n; j ++) {
                int tar = -(nums[i] + nums[j]);
                if (seen.count(tar)) {
                    vector<int> temp {nums[i], nums[j], tar};
                    sort(begin(temp), end(temp));
                    st.insert(temp);
                }
                seen.insert(nums[j]);
            }
        }
        vector<vector<int>> result(begin(st), end(st));
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    void twoSum(vector<int>& nums, vector<vector<int>>& result, int j, int k, int tar) {
        while (j < k) {
            int sum =  nums[j] + nums[k];
            if (sum > tar) {
                k --;
            } else if (sum < tar) {
                j ++;
            } else {
                result.push_back({-(tar), nums[j], nums[k]});
                j ++, k --;

                while (j < k && nums[j] == nums[j - 1]) j ++;
                while (j < k && nums[k] == nums[k + 1]) k --;
            }
        }
    }

    // TC : O(N^2)
    // SC : O(1)
    vector<vector<int>> optimal(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int tar = -(nums[i]); // nums[i] + num[j] + nums[k] = 0
                                  // nums[j] + nums[k]          = -(nums[i])

            twoSum(nums, result, i + 1, n - 1, tar);
        }
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // BRUTE : Use 3-loops
        // return better(nums);
        return optimal(nums);
    }
};