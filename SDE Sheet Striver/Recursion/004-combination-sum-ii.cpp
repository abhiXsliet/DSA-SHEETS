// https://leetcode.com/problems/combination-sum-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    set<vector<int>> st;
/* 
    Time Complexity: O(2^N * K)
      - O(2^N) represents the maximum number of unique combinations generated from N candidates.
      - O(K) accounts for the time taken to copy each valid combination to the result vector,
        where K is the average length of the combinations.
        
    Space Complexity: O(K * X)
      - O(K * X) is the space required to store all unique combinations,
        where K is the average length of the combinations and X is the total number of combinations stored.
      - Additional space for the call stack is O(N) but is overshadowed by the result storage.
*/
    void solveNew(vector<int>& cand, int tar, int idx, vector<int>& store, vector<vector<int>>& res) {
        if (tar <= 0) {
            if (tar == 0) {
                res.push_back(store);
            }
            return;
        }

        for (int i = idx; i < cand.size(); i ++) {
            if (i > idx && cand[i] == cand[i - 1])  // skip duplicate
                continue;
            store.push_back(cand[i]);
            solveNew(cand, tar - cand[i], i + 1, store, res);
            store.pop_back(); 
        }
    }

/* 
    Time Complexity: O(2^N * K log K + K log X)
      - O(2^N) accounts for the number of unique subsequences (where N is the number of candidates)
      - O(K log K) arises from sorting each combination, where K is the average length of combinations
      - O(K log X) accounts for the insertion of combinations into the set, where X is the total number of unique combinations

    Space Complexity: O(K * X)
      - K is the average length of the combinations
      - X is the total number of unique combinations stored
*/
    void solve(vector<int>& cand, int tar, int idx, vector<int> store) {
        if (tar <= 0) {
            if (tar == 0) {
                sort(begin(store), end(store));
                st.insert(store);
            }
            return;
        }

        for (int i = idx; i < cand.size(); i ++) {
            store.push_back(cand[i]);
            solve(cand, tar - cand[i], i + 1, store);
            store.pop_back();
        }
    }

    vector<vector<int>> approach_1(vector<int>& candidates, int target) {
        vector<int> store;
        solve(candidates, target, 0, store);
        vector<vector<int>> result(begin(st), end(st));
        return result;
    }

    vector<vector<int>> approach_2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> result;
        vector<int> store;
        solveNew(candidates, target, 0, store, result);
        return result;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // return approach_1(candidates, target);

        return approach_2(candidates, target);
    }
};