// https://www.interviewbit.com/problems/nearest-smaller-element/




#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> result(n, -1);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i --) {
        while (!stk.empty() && A[i] < A[stk.top()]) {
            result[stk.top()] = A[i];
            stk.pop();
        }
        stk.push(i);
    }
    return result;
}