// https://www.geeksforgeeks.org/problems/rod-cutting0840/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    int n;
    
    int solve(vector<int> &price, int i, int w, vector<vector<int>> &dp) {
        if (i >= n || w == 0) return 0;
        
        if (dp[i][w] != -1) return dp[i][w];
        
        int take = 0;
        // cutting rod of len : (i + 1), profit obtained = price[i]
        if (w >= (i + 1)) { 
            take = price[i] + solve(price, i, w - (i + 1), dp);
        }
        
        int notT = solve(price, i + 1, w, dp);
        
        return dp[i][w] = max(take, notT);
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int top_down(vector<int> &price) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(price, 0, n, dp);
    }
    
    // TC : O(N^2)
    // SC : O(N^2)
    int bottom_up(vector<int> &price) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int w = 1; w <= n; w ++) {
                int take = 0;
                // cutting rod of len : (i + 1), profit obtained = price[i]
                if (w >= (i + 1)) { 
                    take = (w - (i + 1) >= 0) ? price[i] + dp[i][w - (i + 1)] : 0;
                }
                
                int notT = dp[i + 1][w];
                dp[i][w] = max(take, notT);
            }
        }
        return dp[0][n];
    }

    // TC : O(N^2)
    // SC : O(N)
    int space_optimized(vector<int> &price) {
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        for (int i = n - 1; i >= 0; i --) {
            for (int w = 1; w <= n; w ++) {
                int take = 0;
                // cutting rod of len : (i + 1), profit obtained = price[i]
                if (w >= (i + 1)) { 
                    take = (w - (i + 1) >= 0) ? price[i] + curr[w - (i + 1)] : 0;
                }
                
                int notT = prev[w];
                curr[w] = max(take, notT);
            }
            prev = curr;
        }
        return prev[n];
    }
  public:
    int cutRod(vector<int> &price) {
        n = price.size();
        
        // return top_down(price);
        // return bottom_up(price);
        return space_optimized(price);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends