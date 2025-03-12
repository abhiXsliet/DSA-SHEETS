// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379




#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
typedef tuple<int, int, int> T;

// TC : O(N*log(K))
// SC : O(K)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    int n = kArrays.size();
    priority_queue<T, vector<T>, greater<T>> minHeap;
    for (int i = 0; i < n; i ++) {
        if (!kArrays[i].empty()) {
            minHeap.push(make_tuple(kArrays[i][0], i, 0));
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        int mini, arrIdx, eleIdx;
        tie(mini, arrIdx, eleIdx) = minHeap.top();
        minHeap.pop();

        result.push_back(mini);

        // Insert the next element from the same array into heap
        if (eleIdx + 1 < kArrays[arrIdx].size()) {
            minHeap.push(make_tuple(kArrays[arrIdx][eleIdx + 1], arrIdx, eleIdx + 1));
        }
    }
    return result;
}