// https://www.interviewbit.com/problems/subarray-with-given-xor/



#include <bits/stdc++.h>
using namespace std;

// BRUTE  : O(N^3) Three loops for subarray and return the cnt of subarray whose xor is B
// BETTER : O(N^2) Two loops for subarray and return the cnt of subarray whose xor is B

int Solution::solve(vector<int> &arr, int B) {
    int n = arr.size();
    unordered_map<int, int> mpp;    // {xor, cnt}
    mpp[0] = 1;
    int cntSubArr = 0;
    int xor_all   = 0;

    for (int i = 0; i < n; i ++) {
        xor_all ^= arr[i];
        if (mpp.count(xor_all ^ B)) {
            cntSubArr += mpp[xor_all ^ B];
        }
        mpp[xor_all] ++;
    }
    
    return cntSubArr;
}
