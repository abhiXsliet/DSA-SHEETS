// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n - 1; i++) {
            mini = min(mini, prices[i]);

            profit = max(profit, prices[i+1] - mini);
        }
        
        return profit;
    }
};