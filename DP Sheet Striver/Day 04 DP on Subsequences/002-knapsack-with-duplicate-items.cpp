// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    int n;
    
    int solve(vector<int> &val, vector<int> &wt, int i, int cap, vector<vector<int>> &dp) {
        if (!cap || i >= n) 
            return 0;
        
        if (dp[i][cap] != -1)
            return dp[i][cap];
        
        int take = 0;
        if (cap >= wt[i]) {
            take = max(take, val[i] + solve(val, wt, i, cap - wt[i], dp));
        }
        int notT = solve(val, wt, i + 1, cap, dp);
        
        return dp[i][cap] = max(take, notT);
    }
    
    // TC : O(N * Capacity)
    // SC : O(N * Capacity) 
    int top_down(vector<int> &val, vector<int> &wt, int cap) {
        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
        return solve(val, wt, 0, cap, dp);
    }

    // TC : O(N * Capacity)
    // SC : O(N * Capacity) 
    int bottom_up(vector<int> &val, vector<int> &wt, int capacity) {
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        for (int i = 0; i <= n; i ++)  // Base case : if there's no capacity then value picked will be 0
            dp[i][0] = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int cap = 1; cap <= capacity; cap ++) {
                int take = 0;
                if (cap >= wt[i]) {
                    take = max(take, val[i] + dp[i][cap - wt[i]]);
                }
                int notT = dp[i + 1][cap];
                
                dp[i][cap] = max(take, notT);
            }
        }
        
        return dp[0][capacity];
    }
    
    // TC : O(N * Capacity)
    // SC : O(Capacity) 
    int space_optimized(vector<int> &val, vector<int> &wt, int capacity) {
        vector<int> curr(capacity + 1, 0), prev(capacity + 1, 0);
        
        for (int i = 0; i <= n; i ++)  // Base case : if there's no capacity then value picked will be 0
            curr[0] = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int cap = 1; cap <= capacity; cap ++) {
                int take = 0;
                if (cap >= wt[i]) {
                    take = max(take, val[i] + curr[cap - wt[i]]);
                }
                int notT = prev[cap];
                
                curr[cap] = max(take, notT);
            }
            prev = curr;
        }
        
        return prev[capacity];
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        n = val.size();
        
        // return top_down(val, wt, capacity);
        // return bottom_up(val, wt, capacity);
        return space_optimized(val, wt, capacity);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends