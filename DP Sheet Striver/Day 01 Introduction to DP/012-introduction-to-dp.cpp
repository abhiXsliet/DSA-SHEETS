// https://www.geeksforgeeks.org/problems/introduction-to-dp/1




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int M = 1e9 + 7;
    using lli = long long int;
    
    lli f(int n, vector<lli> &dp) {
        if (n <= 1)
            return n == 0 ? 0 : 1;
            
        if (dp[n] != -1) return dp[n];
            
        return dp[n] = (f(n - 1, dp) + f(n - 2, dp)) % M;
    }
    
    long long int topDown(int n) {
        vector<lli> dp(n + 1, -1);
        return f(n, dp);
    }
    
    long long int bottomUp(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends