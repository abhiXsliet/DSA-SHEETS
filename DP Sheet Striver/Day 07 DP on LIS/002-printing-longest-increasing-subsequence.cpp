// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // This soln. is intutively different than other solns. (prev, curr approach)
        
        vector<int> dp(n, 1);   // dp[i] : lis ending at i
        
        vector<int> hash(n);    // used to backtrack and find lis
        for (int i = 0; i < n; i ++) 
            hash[i] = i;
            
        int maxLis = 0, lastIdx = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (arr[i] > arr[j] && dp[i] < 1 + dp[j]) {
                    dp[i]   = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxLis) {
                maxLis  = dp[i];
                lastIdx = i;
            }
        }
        
        vector<int> result;
        while (lastIdx != hash[lastIdx]) {
            result.push_back(arr[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        result.push_back(arr[lastIdx]);
        
        reverse(begin(result), end(result));
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
    cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends