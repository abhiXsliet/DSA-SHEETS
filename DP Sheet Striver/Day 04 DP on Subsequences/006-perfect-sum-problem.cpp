// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// Count Subsets with Sum K (DP - 17)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    
    int solve(vector<int> &arr, int i, int target, vector<vector<int>> &dp) {
        if (i >= n || target < 0) {
            return target == 0 ? 1 : 0;
        }    
        
        if (dp[i][target] != -1)
            return dp[i][target];
        
        int op1 = solve(arr, i + 1, target - arr[i], dp);
        int op2 = solve(arr, i + 1, target, dp);
        
        return dp[i][target] = (op1 + op2);
    }
    
    // TC : O(N * target)
    // SC : O(N * target)
    int top_down(vector<int> &arr, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(arr, 0, target, dp);
    }

    // TC : O(N * target)
    // SC : O(N * target)
    int bottom_up(vector<int> &arr, int tar) {
        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int target = 0; target <= tar; target ++) {
                int op1 = (target - arr[i] >= 0) ? dp[i + 1][target - arr[i]] : 0;
                int op2 = dp[i + 1][target];
                
                dp[i][target] = (op1 + op2);
            }
        }
        return dp[0][tar];
    }

    // TC : O(N * target)
    // SC : O(target)
    int space_optimized(vector<int> &arr, int tar) {
        vector<int> curr(tar + 1, 0), prev(tar + 1, 0);
        curr[0] = prev[0] = 1;
        for (int i = n - 1; i >= 0; i --) {
            for (int target = 0; target <= tar; target ++) {
                int op1 = (target - arr[i] >= 0) ? prev[target - arr[i]] : 0;
                int op2 = prev[target];
                
                curr[target] = (op1 + op2);
            }
            prev = curr;
        }
        return prev[tar];
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        n = arr.size();
        
        // return top_down(arr, target);
        // return bottom_up(arr, target);
        return space_optimized(arr, target);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends