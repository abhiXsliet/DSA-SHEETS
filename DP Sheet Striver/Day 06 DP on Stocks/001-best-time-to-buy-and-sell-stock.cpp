// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &prices) {
        int n = prices.size();
        int i = 0, j = 0;
        int profit = 0;
        while (j < n) {
            if (prices[j] < prices[i]) {
                i = j;
            }
            profit = max(profit, prices[j] - prices[i]);
            j ++;
        }
        return profit;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &prices) {
        int n = prices.size();
        int profit = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i ++) {
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // return approach_1(prices);

        return approach_2(prices);
    }
};