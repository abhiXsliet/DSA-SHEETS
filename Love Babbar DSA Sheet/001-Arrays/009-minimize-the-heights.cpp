// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // TC = O(N)
    // SC = O(1)
    int getMinDiff(int arr[], int n, int k) {
        // step-1 : sort the array
        sort(arr, arr + n);
        
        // step-2 : fix the min and max values
        int minVal = arr[0];
        int maxVal = arr[n - 1];
        
        int minHeight = maxVal - minVal;
        
        // step-3 : initialize variable to track the min and max
        int mini = 0;
        int maxi = 0;
        
        for (int i = 1; i < n; i++) {
            // step-4 : choti value ko increase and badi ko decrease (iff decrement is >= 0)
            if (arr[i] - k >= 0) {
                // find max by increase smaller element and decreasing maxVal 
                maxi = max(arr[i-1] + k, maxVal - k);
                // find min by decreasing greater element and increasing minVal 
                mini = min(arr[i] - k,  minVal + k);
                // calculate minimum height
                minHeight = min(minHeight, (maxi - mini));
            }
            else {
                continue;
            }
        }
        return minHeight;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends