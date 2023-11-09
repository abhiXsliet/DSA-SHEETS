// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/


#include <bits/stdc++.h>
using namespace std;

// Approach - 1
// TC = O(N * log(N))
// SC = O(1)
pair<int, int> getMinMax(int arr[], int n) {
    sort(arr, arr + n);

    int mini = arr[0];
    int maxi = arr[n - 1];

    return {mini, maxi};
}


int main() {
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int n     = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> P = getMinMax(arr, n);

    cout << "\nMinimum Number is : " << P.first << endl;
    cout << "\nMaximum Number is : " << P.second << endl;

    return 0;
}