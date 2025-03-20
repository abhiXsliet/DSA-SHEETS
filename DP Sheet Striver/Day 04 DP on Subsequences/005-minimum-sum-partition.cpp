// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &arr, int total, int i, int sum, vector<vector<int>> &dp) {
        if (i == n) {
            return abs((total - sum) - sum);
        }
        
        if (dp[i][sum] != -1) 
            return dp[i][sum];
        
        int op1 = solve(arr, total, i + 1, sum + arr[i], dp);
        int op2 = solve(arr, total, i + 1, sum, dp);
        
        return dp[i][sum] = min(op1, op2);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int top_down(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
        return solve(arr, total, 0, 0, dp);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int bottom_up(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));
        for (int sum = 0; sum <= total; sum ++) {
            dp[n][sum] = abs((total - sum) - sum);
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 0; sum <= total; sum ++) {
                int op1 = (sum + arr[i] >= 0) ? dp[i + 1][sum + arr[i]] : 0;
                int op2 = dp[i + 1][sum];
                
                dp[i][sum] = min(op1, op2);
            }
        }
        return dp[0][0];
    }

    // TC : O(N * Sum)
    // SC : O(Sum)
    int space_optimized(vector<int> &arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        
        vector<int> curr(total + 1, 0), prev(total + 1, 0);
        for (int sum = 0; sum <= total; sum ++) {
            prev[sum] = abs((total - sum) - sum);
        }

        for (int i = n - 1; i >= 0; i --) {
            for (int sum = 0; sum <= total; sum ++) {
                int op1 = (sum + arr[i] >= 0) ? prev[sum + arr[i]] : 0;
                int op2 = prev[sum];
                
                curr[sum] = min(op1, op2);
            }
            prev = curr;
        }
        return prev[0];
    }
  public:
    int minDifference(vector<int>& arr) {
        n = arr.size();
        
        // return top_down(arr);
        // return bottom_up(arr);
        return space_optimized(arr);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends