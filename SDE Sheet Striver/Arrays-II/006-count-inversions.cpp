// https://www.naukri.com/code360/problems/count-inversions_615



#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *nums, int start, int mid, int end) {
    ll cnt = 0;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    ll *left  = new ll[n1];
    ll *right = new ll[n2];

    int i = 0, j = 0, k = start;
    for (; i < n1; i ++) left[i]  = nums[k++];
    for (; j < n2; j ++) right[j] = nums[k++];

    i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            k ++, i ++;
        }
        else {
            cnt += (n1 - i);
            nums[k] = right[j];
            k ++, j ++;
        }
    }
    
    for (; i < n1; i ++) nums[k++] = left[i];
    for (; j < n2; j ++) nums[k++] = right[j];

    delete[] left;
    delete[] right;

    return cnt;
}

// TC : O(N*log(N))
// SC : O(N)
ll mergeSort(ll *arr, int low, int high) {
    int cntInv = 0;
    if (low >= high) return 0;
    int mid = (low + high) >> 1;
    cntInv += mergeSort(arr, low, mid);
    cntInv += mergeSort(arr, mid + 1, high);
    cntInv += merge(arr, low, mid, high);
    return cntInv;
}

ll getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}