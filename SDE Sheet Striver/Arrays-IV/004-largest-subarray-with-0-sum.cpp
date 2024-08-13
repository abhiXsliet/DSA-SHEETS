// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  private:
    // TC = O(N^3)
    // SC = O(1)
    int brute(vector<int>& arr, int n) {
        int maxL = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                    
                    if (sum == 0) {
                        maxL = max(maxL, k - i + 1);
                    }
                }
            }
        }
        return maxL;
    }
   
    // TC = O(N^2)
    // SC = O(1) 
    int better(vector<int>& arr, int n) {
        int maxL = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    maxL = max(maxL, j - i + 1);
                }
            }
        }
        return maxL;
    }
    // TC : O(N)
    // SC : O(N)
    int optimal(vector<int>& arr, int n) {
        unordered_map<int, int> mpp;
        int sum  = 0;
        mpp[sum] = 0;
        int maxL = 0;
        for (int i = 0; i < n; i ++) {
            sum += arr[i];
            if (mpp.count(sum)) {
                maxL = max(maxL, (i + 1) - mpp[sum]);
            }
            else mpp[sum] = (i + 1);
        }
        return maxL;
    }
  public:
    int maxLen(vector<int>& arr, int n) {
        // return brute(arr, n);

        // return better(arr, n);

        return optimal(arr, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}
// } Driver Code Ends