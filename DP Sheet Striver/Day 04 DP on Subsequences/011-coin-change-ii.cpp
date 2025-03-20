// https://leetcode.com/problems/coin-change-ii/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    
    int solve(vector<int> &coins, int i, int amount, vector<vector<int>> &dp) {
        if (i >= n || amount <= 0) {
            return amount == 0;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int op1 = solve(coins, i, amount - coins[i], dp);
        int op2 = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = (op1 + op2);
    }

    // TC : O(n * amount)
    // SC : O(n * amount)
    int top_down(vector<int> &coins, int amount) {
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(coins, 0, amount, dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        
        return top_down(coins, amount);
    }
};