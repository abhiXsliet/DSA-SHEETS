// https://leetcode.com/problems/coin-change/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    
    int solve(vector<int> &coins, int i,int amount, vector<vector<int>> &dp) {
        if (i >= n || amount <= 0) {
            return amount == 0 ? 0 : 1e5;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int op1 = 1 + solve(coins, i, amount - coins[i], dp);
        int op2 = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = min(op1, op2);
    }

    // TC : O(n * amount)
    // SC : O(n * amount)
    int top_down(vector<int> &coins, int amount) {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, 0, amount, dp);
        return ans == 1e5 ? -1 : ans;
    }

    // TC : O(n * amount)
    // SC : O(n * amount)
    int bottom_up(vector<int> &coins, int A) {
        vector<vector<int>> dp(n + 1, vector<int>(A + 1, 1e5));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 0;
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int amount = 1; amount <= A; amount ++) {
                int op1 = (amount - coins[i] >= 0) ? 1 + dp[i][amount - coins[i]] : 1e5;
                int op2 = dp[i + 1][amount];
                dp[i][amount] = min(op1, op2);
            }
        }
        int ans = dp[0][A];
        return ans == 1e5 ? -1 : ans;
    }

    // TC : O(n * amount)
    // SC : O(amount)
    int space_optimized(vector<int> &coins, int A) {
        vector<int> curr(A + 1, 1e5), prev(A + 1, 1e5);
        
        curr[0] = prev[0] = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int amount = 1; amount <= A; amount ++) {
                int op1 = (amount - coins[i] >= 0) ? 1 + curr[amount - coins[i]] : 1e5;
                int op2 = prev[amount];
                curr[amount] = min(op1, op2);
            }
            prev = curr;
        }
        int ans = prev[A];
        return ans == 1e5 ? -1 : ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        // return top_down(coins, amount);
        // return bottom_up(coins, amount);
        return space_optimized(coins, amount);
    }
};