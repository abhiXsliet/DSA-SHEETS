// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(n)
    // SC : O(1)
    int solve_1(vector<int>& prices) {
        int mini   = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - mini;
            profit   = max(profit, diff);
            mini     = min(mini, prices[i]);
        }
        
        return profit;
    }

    int solve_2(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        
        int n = prices.size();
        for (int i = 0; i < n - 1; i++) {
            mini = min(mini, prices[i]);

            profit = max(profit, prices[i+1] - mini);
        }
        
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // return solve_1(prices);

        return solve_2(prices);
    }
};