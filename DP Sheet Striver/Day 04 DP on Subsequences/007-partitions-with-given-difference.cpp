// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

// Variation of the subset sum problem: find a subset that sums to a modified target value.


//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    int t[51][150][150];
    int dp[51][150];
    
    int solve_optimal(vector<int> &arr, int i, int tar) {
        if (i == n || tar < 0) {
            return tar == 0 ? 1 : 0;
        }
        
        if (dp[i][tar] != -1) 
            return dp[i][tar];
        
        int op1 = solve_optimal(arr, i + 1, tar - arr[i]);
        int op2 = solve_optimal(arr, i + 1, tar);
        
        return dp[i][tar] = (op1 + op2);
    }
    
    int solve_better(vector<int> &arr, int d, int total, int i, int sum1) {
        if (i == n) {
            int sum2 = total - sum1;
            if (sum1 >= sum2) {
                return (sum1 - sum2) == d ? 1 : 0;
            }
            return 0;
        }
        
        if (dp[i][sum1] != -1) 
            return dp[i][sum1];
        
        int op1 = solve_better(arr, d, total, i + 1, sum1 + arr[i]);
        int op2 = solve_better(arr, d, total, i + 1, sum1);
        
        return dp[i][sum1] = (op1 + op2);
    }
    
    int solve(vector<int> &arr, int d, int i, int sum1, int sum2) {
        if (i == n) {
            if (sum1 >= sum2) {
                return (sum1 - sum2) == d ? 1 : 0;
            }
            return 0;
        }
        
        if (t[i][sum1][sum2] != -1) 
            return t[i][sum1][sum2];
        
        int op1 = solve(arr, d, i + 1, sum1 + arr[i], sum2);
        int op2 = solve(arr, d, i + 1, sum1, sum2 + arr[i]);
        
        return t[i][sum1][sum2] = (op1 + op2);
    }
    
    // TC : O(N * Sum * Sum)
    // SC : O(N * Sum * Sum)
    int top_down(vector<int> &arr, int d) {
        memset(t, -1, sizeof(t));
        return solve(arr, d, 0, 0, 0);
    }
    
    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int top_down_better(vector<int> &arr, int d) {
        int total = accumulate(begin(arr), end(arr), 0);
        memset(dp, -1, sizeof(dp));
        return solve_better(arr, d, total, 0, 0);
    }

    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int top_down_optimal(vector<int> &arr, int d) {
        int total = accumulate(begin(arr), end(arr), 0);
        
        // s1 - s2 = d  (where s1 >= s2) ------------> I
        // total = s1 + s2 => [s1 = total - s2]  -----> II
        // total = 2s2 + d => [s2 = (total - d) / 2]    (using II in I)
        int sum2 = (total - d) / 2;   
        
        if ((total - d) < 0 || (total - d) % 2)
            return 0;
        
        memset(dp, -1, sizeof(dp));
        return solve_optimal(arr, 0, sum2);
    }

    // TC : O(N * Sum)
    // SC : O(N * Sum)
    int bottom_up(vector<int> &arr, int d) {
        int total = accumulate(begin(arr), end(arr), 0);
        
        // s1 - s2 = d  (where s1 >= s2) ------------> I
        // total = s1 + s2 => [s1 = total - s2]  -----> II
        // total = 2s2 + d => [s2 = (total - d) / 2]    (using II in I)
        int sum2 = (total - d) / 2;   
        
        if ((total - d) < 0 || (total - d) % 2)
            return 0;
            
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i --) {
            for (int tar = 0; tar <= sum2; tar ++) {
                int op1 = (tar - arr[i] >= 0) ? dp[i + 1][tar - arr[i]] : 0;
                int op2 = dp[i + 1][tar];
                
                dp[i][tar] = (op1 + op2);
            }
        }
        return dp[0][sum2];
    }
    
    // TC : O(N * Sum)
    // SC : O(Sum)
    int space_optimized(vector<int> &arr, int d) {
        int total = accumulate(begin(arr), end(arr), 0);
        
        // s1 - s2 = d  (where s1 >= s2) ------------> I
        // total = s1 + s2 => [s1 = total - s2]  -----> II
        // total = 2s2 + d => [s2 = (total - d) / 2]    (using II in I)
        int sum2 = (total - d) / 2;   
        
        if ((total - d) < 0 || (total - d) % 2)
            return 0;
            
        vector<int> curr(total + 1, 0), prev(total + 1, 0);

        curr[0] = prev[0] = 1;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int tar = 0; tar <= sum2; tar ++) {
                int op1 = (tar - arr[i] >= 0) ? prev[tar - arr[i]] : 0;
                int op2 = prev[tar];
                
                curr[tar] = (op1 + op2);
            }
            prev = curr;
        }
        return prev[sum2];
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        n = arr.size();
        
        // return top_down(arr, d);          // 3D DP
        // return top_down_better(arr, d);   // 2D DP
        // return top_down_optimal(arr, d);  // 2D DP : find subset with a modified target sum
        // return bottom_up(arr, d);
        return space_optimized(arr, d);
    }
};


//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends