// https://leetcode.com/problems/4sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^3)
    // SC : O(No. of Quadruplets)
    vector<vector<int>> better(vector<int>& nums, int tar) {
        int n = nums.size();
        set<vector<int>> store;    // store unique quadruplets

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                
                unordered_set<long> st;
                for (int k = j + 1; k < n; k ++) {
                    
                    long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long req = tar - sum;

                    if (st.find(req) != st.end()) {
                        vector<int> temp{nums[i], nums[j], nums[k], (int)req};
                        sort(begin(temp), end(temp));
                        store.insert(temp);
                    }

                    st.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> result (store.begin(), store.end());
        return result;
    }

    // TC : O(N^3)
    // SC : O(1)
    vector<vector<int>> optimal(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(begin(nums), end(nums));
        for (int i = 0; i < n - 3; i ++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
           
            for (int j = i + 1; j < n - 2; j ++) {

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // catch

                int k = j + 1;
                int r = n - 1;

                while (k < r) {
                    long sum = nums[i];
                    sum     += nums[j];
                    sum     += nums[k];
                    sum     += nums[r];

                    if (sum == tar) {
                        vector<int> temp {nums[i], nums[j], nums[k], nums[r]};
                        sort(begin(temp), end(temp));
                        result.push_back(temp);
                        k ++;
                        r --;

                        while (k < r && nums[k] == nums[k - 1]) k ++;  
                        while (k < r && nums[r] == nums[r + 1]) r --;

                    } else if (sum > tar) r --;
                    else k ++;
                }
            }
        }
        return result;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // return better(nums, target);

        return optimal(nums, target);
    }
};