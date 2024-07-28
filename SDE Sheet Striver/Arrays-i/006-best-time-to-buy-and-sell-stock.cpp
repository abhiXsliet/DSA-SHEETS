// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int way_1(vector<int>& prices, int n) {
        int minPrice  = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < n; i ++) {
            int profit = prices[i] - minPrice;
            maxProfit  = max(profit, maxProfit);
            minPrice   = min(minPrice, prices[i]);
        }
        return maxProfit;
    }

    // TC : O(N)
    // SC : O(1)
    int way_2(vector<int>& prices, int n) {
        int minPrice  = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < n - 1; i ++) {
            minPrice   = min(minPrice, prices[i]);

            maxProfit  = max(maxProfit, prices[i + 1] - minPrice);
        }
        return maxProfit;
    }
public:
    int maxProfit(vector<int>& prices) {
        // return way_1(prices, prices.size());

        return way_2(prices, prices.size());
    }
};