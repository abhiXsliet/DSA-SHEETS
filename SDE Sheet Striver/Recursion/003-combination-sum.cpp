// https://leetcode.com/problems/combination-sum/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
/* 
    Time Complexity: O(2^T * K)
      - O(2^T) accounts for the maximum depth of the recursive tree,
      - K represents the average length of the combinations generated.

    Space Complexity: O(K * X)
      - O(K * X) is the space required to store all valid combinations,
        where X is the total number of combinations and K is the average length of each combination
*/
    void solve(vector<int>& cand, int tar, int idx, vector<int>& store, vector<vector<int>>& res) {
        if (tar <= 0) {
            if (tar == 0) {
                res.push_back(store);
            }
            return;
        }

        for (int i = idx; i < cand.size(); i ++) {
            store.push_back(cand[i]);
            solve(cand, tar - cand[i], i, store, res);
            store.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> store;
        solve(candidates, target, 0, store, result);
        return result;
    }
};