// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{ 
private:
    // TC = O(N * N)
    // SC = O(1)
    int solve_brute(int arr[], int n, int k) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == k) cnt++;
            }
        }
        return cnt;
    }
    
    // TC = O(N)
    // SC = O(N)
    int solve_optimal(int arr[], int n, int k) {
        unordered_map<int, int> mpp;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int target = k - arr[i];
            if (mpp.find(target) != mpp.end()) {
                cnt += mpp[target];
            }
            mpp[target]++;
        }
        return cnt;
    }
public:
    int getPairsCount(int arr[], int n, int k) {
        // return solve_brute(arr, n, k);
        
        return solve_optimal(arr, n, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends