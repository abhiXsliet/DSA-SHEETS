// https://leetcode.com/problems/subsets-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> subset;
    set<vector<int>> st;

    void funcOptimal(vector<int>& nums, vector<vector<int>>& result, int idx) {
        result.push_back(subset);   // at each level we're adding all generated subsets to answer

        for (int i = idx; i < nums.size(); i ++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            funcOptimal(nums, result, i + 1);
            subset.pop_back();      // Backtrack
        }
    }
    
    // TC : O(2^N)
    // SC : O(N)    Recursive Stack Space
    void solve(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            st.insert(subset);
            return;
        }

        subset.push_back(nums[idx]);   // Take & explore
        solve(nums, idx + 1);
        subset.pop_back();             // Backtrack (Not Take) & explore
        solve(nums, idx + 1);
    }

    // TC : O(2^N + log(2^N) * 2^N )  for generating every subset and storing it into set
    // SC : O(N * 2^N)                storing unique subset is O(2^N) & each subset can have a size up to N (in the worst case)
    vector<vector<int>> brute(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(begin(nums), end(nums));

        solve(nums, 0);

        for (vector<int> v : st) {
            result.push_back(v);
        }

        return result;
    }

    // TC : O(2^N * N)  Generating every subsets takes O(2^N) * (N) for inserting each subset of average length N into answer
    // SC : O(2^N * N)  Storing every subsets takes O(2^N) * (N) average length of each subset 
    // SC : O(N)        Max Recusive Depth
    vector<vector<int>> optimal(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));   // sort to skip duplicate
        funcOptimal(nums, result, 0);
        return result;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // return brute(nums);      // Sorting nums + Set :  then store and generate all subset of nums in set

        return optimal(nums);       // Sorting num + Without Set : Skip duplicates on the go
    }
};