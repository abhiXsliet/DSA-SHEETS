// https://www.geeksforgeeks.org/problems/minimal-cost/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int solve(vector<int>& arr, int n, int k, int idx, vector<int> &dp) {
        if (idx == n - 1) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int ans = INT_MAX;
        for (int i = 1; i <= k && i + idx < n; i ++) {
            ans = min(ans, abs(arr[idx] - arr[idx + i]) + solve(arr, n, k, idx + i, dp));
        }
        return dp[idx] = ans;
    }
    
    // TC : O(N*K)
    // SC : O(N)
    int approach_1(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(arr, n, k, 0, dp);
    }

    // TC : O(N*K)
    // SC : O(N)
    int approach_2(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        
        for (int idx = n - 2; idx >= 0; idx --) {
            int ans = INT_MAX;
            for (int i = 1; i <= k && i + idx < n; i ++) {
                ans = min(ans, abs(arr[idx] - arr[idx + i]) + dp[idx + i]);
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // return approach_1(arr, k);   // Top-Down
        return approach_2(arr, k);   // Bottom-Up : here space optimization is not possible
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
// } Driver Code Ends