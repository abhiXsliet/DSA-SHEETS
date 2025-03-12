// https://leetcode.com/problems/online-stock-span/




#include <bits/stdc++.h>
using namespace std;

// TC : O(1) Amortized O(1) because average cost per operation is constant, even if some individual operations are expensive.
// SC : O(N)
class StockSpanner {
public:
    stack<pair<int, int>> stk;  // {element, cnt}
    StockSpanner() {}
    
    int next(int price) {
        if (stk.empty()) {
            stk.push({price, 1});
            return 1;
        } 
        int stockCnt = 1;
        while (!stk.empty() && stk.top().first <= price) {
            stockCnt += (stk.top().second);
            stk.pop();
        }
        stk.push({price, stockCnt});
        return stockCnt;
    }
};