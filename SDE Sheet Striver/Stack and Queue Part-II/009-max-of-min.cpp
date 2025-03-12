// https://www.naukri.com/code360/problems/max-of-min_982935




#include <bits/stdc++.h> 
using namespace std;

// TC : O(N^2)
// SC : O(1)
vector<int> brute(vector<int>& arr, int n) {
    vector<int> result(n, INT_MIN);
    for (int i = 0; i < n; i ++) {
        int mini = INT_MAX;
        for (int len = i; len < n; len ++) {
            mini = min(mini, arr[len]);
            result[len - i] = max(result[len - i], mini);
        }
    }
    return result;
}

// TC : O(N)
// SC : O(N)
vector<int> optimal(vector<int>& arr, int n) {
    // Avoiding : Extra space for nse and pse, calculating it while traversing on the go
    vector<int> result(n, INT_MIN);
    stack<int> stk;
    for (int i = 0; i < n; i ++) {
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            int nse  = i;
            int rIdx = stk.top();   // rIdx = resultant index for which nse is founded
            stk.pop();

            int pse = stk.empty() ? -1 : stk.top();
            
            int lastRange = nse - pse - 1;   // lastRangeIdx = lastRange - 1
            int lRI = lastRange - 1;    // lRI = lastRangeIdx
            result[lRI] = max(result[lRI], arr[rIdx]);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        int nse  = n;
        int rIdx = stk.top();
        stk.pop();

        int pse = stk.empty() ? -1 : stk.top();

        int lastRange = nse - pse - 1;
        int lRI = lastRange - 1;
        result[lRI] = max(result[lRI], arr[rIdx]);
    }
    for (int i = n - 2; i >= 0; i --) {
        result[i] = max(result[i], result[i + 1]); 
    }
    return result;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    // return brute(a, n);
    return optimal(a, n);   
}