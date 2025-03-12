// https://www.interviewbit.com/problems/maximum-sum-combinations/




#include <bits/stdc++.h>
using namespace std;

// TC : O(N*log(N) + M*log(M)) Where N = A.size() and M = B.size()
// SC : O(N + M)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort (rbegin(A), rend(A));
    sort (rbegin(B), rend(B));
    
    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> visited;
    vector<int> result;
    
    maxHeap.push({A[0] + B[0], 0, 0});
    visited.insert({0, 0});
    
    while (!maxHeap.empty() && C--) {
        auto [sum, i, j] = maxHeap.top();
        maxHeap.pop();
        
        result.push_back(sum);
        
        if (i + 1 < A.size() && !visited.count({i + 1, j})) {
            maxHeap.push({A[i + 1] + B[j], i + 1, j});
            visited.insert({i + 1, j});
        }
        
        if (j + 1 < B.size() && !visited.count({i, j + 1})) {
            maxHeap.push({A[i] + B[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }
    return result;
}