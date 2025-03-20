// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

// similar : https://leetcode.com/problems/maximum-length-of-repeated-subarray/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int m, n;
    unordered_map<string, int> mpp;
    
    int solve(string &s1, string &s2, int i, int j, int maxL) {
        if (i == m || j == n)
            return maxL;
            
        string key = to_string(i) + "," + to_string(j) + "," + to_string(maxL);
        if (mpp.count(key))
            return mpp[key];
            
        int same = maxL;    
        if (s1[i] == s2[j]) {
            same = solve(s1, s2, i + 1, j + 1, maxL + 1);
        }
        
        int op1 = solve(s1, s2, i + 1, j, 0);
        int op2 = solve(s1, s2, i, j + 1, 0);
        
        return mpp[key] = max({same, op1, op2});
    }
    
    // TC : O(M * N * min(M, N))
    // SC : O(M * N * min(M, N))
    int way_1(string &s1, string &s2) {
        mpp.clear();
        return solve(s1, s2, 0, 0, 0);
    }
    
    // TC : O(M * N)
    // SC : O(M * N)
    int way_2(string &s1, string &s2) {
        int maxL = 0;
        
        // dp[i][j] : Length of longestCommonSubstr that ends at s1[i] & s2[j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = m - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
                maxL = max(maxL, dp[i][j]);
            }
        }
        
        return maxL;
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        m = s1.length(), n = s2.length();
    
        // return way_1(s1, s2);
        return way_2(s1, s2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends