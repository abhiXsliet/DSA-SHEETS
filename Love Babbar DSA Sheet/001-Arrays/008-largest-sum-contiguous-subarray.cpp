// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/


#include <bits/stdc++.h>    
using namespace std;

vector<int> largest_sum_subarray(int arr[], int size) {
    
    int maxSum   = INT_MIN;
    int sum      = 0;
    int start    = 0;
    int ansStart = 0;
    int ansEnd   = 0;

    for (int i = 0; i < size; i++) {

        if (sum == 0) 
            start = i;

        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd   = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    
    vector<int> result;
    int resultSum = 0;
    for (int i = ansStart; i <= ansEnd; i++) {
        result.push_back(arr[i]);
        resultSum += arr[i];
    }

    cout << "\nLargest Sum of continuous subarray is : " 
         << resultSum << endl;

    return result;
}

int main() {
    int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int     n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = largest_sum_subarray(arr, n);

    cout << "\nPrinting the largest sum sub-array : " << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " "; 
    }
    cout << " ]" << endl;

    cout << endl;
    return 0;
}