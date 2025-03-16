// https://www.geeksforgeeks.org/problems/geek-jump/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int solve(vector<int> &ht, int i, vector<int> &dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        
        int op1 = abs(ht[i] - ht[i - 1]) + solve(ht, i - 1, dp);
        int op2 = INT_MAX;
        if (i - 2 >= 0) {
            op2 = abs(ht[i] - ht[i - 2]) + solve(ht, i - 2, dp);
        }
        
        return dp[i] = min(op1, op2);
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int> &ht) {
        int n = ht.size();
        vector<int> dp(n + 1, -1);
        return solve(ht, n - 1, dp);
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int> &ht) {
        int n = ht.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i < n; i ++) {
            int op1 = abs(ht[i] - ht[i - 1]) + dp[i - 1];
            int op2 = INT_MAX;
            if (i - 2 >= 0) {
                op2 = abs(ht[i] - ht[i - 2]) + dp[i - 2];
            }
            dp[i] = min(op1, op2);
        }
        
        return dp[n - 1];
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int> &ht) {
        int n = ht.size();
        int prev1 = 0, prev2 = 0;
        for (int i = 1; i < n; i ++) {
            int op1 = abs(ht[i] - ht[i - 1]) + prev1;
            int op2 = INT_MAX;
            if (i - 2 >= 0) {
                op2 = abs(ht[i] - ht[i - 2]) + prev2;
            }
            int curr = min(op1, op2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  public:
    int minCost(vector<int>& height) {
        // return approach_1(height);
        // return approach_2(height);
        return approach_3(height);
    }
};

//{ Driver Code Starts.
int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends