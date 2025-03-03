// https://www.interviewbit.com/problems/allocate-books/



#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

// TC : O(N)
// SC : O(1)
// Is it possible to allocate books to k students within pageLimit
bool isPossible(vector<int>& arr, int k, int pageLimit) {
    int studentCnt = 1;
    int sumPages   = 0;
    for (int& page : arr) {
        if (page + sumPages <= pageLimit) {
            sumPages += page;
        } else {
            studentCnt += 1;
            sumPages    = page;
        }
    }
    return studentCnt <= k; 
}

// TC : O(N * (sum(arr) - max_element))
// SC : O(1)
int approach_1(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    int low  = *max_element(begin(arr), end(arr));
    int high = accumulate(begin(arr), end(arr), 0);
    int ans  =  -1;
    for (int i = low; i <= high; i ++) {
        if (isPossible(arr, k, i)) {
            ans = i;
            break;
        }
    }
    return ans;
}


// TC : O(N * log(sum))
// SC : O(1)
int approach_2(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    
    int low  = *max_element(begin(arr), end(arr));
    int high = accumulate(begin(arr), end(arr), 0);
    int ans  = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid)) {
            ans  = mid;
            high = mid - 1; // minimize answer
        } else {
            low  = mid + 1;
        }
    }
    return ans;
}

int books(vector<int> &arr, int k) {
    // return approach_1(arr, k);  // brute
    return approach_2(arr, k);  // optimal
}
