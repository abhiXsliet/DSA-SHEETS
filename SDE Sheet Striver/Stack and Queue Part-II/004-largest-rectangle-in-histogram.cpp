// https://leetcode.com/problems/largest-rectangle-in-histogram/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(N)
    vector<int> getNse(vector<int>& heights, int n) {
        vector<int> result(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> getPse(vector<int>& heights, int n) {
        vector<int> result(n, -1);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                result[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = getNse(heights, n);
        vector<int> pse = getPse(heights, n);

        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int nse = i;
                int pos = stk.top();
                stk.pop();
                int pse = stk.empty() ? -1 : stk.top();

                int width = nse - pse - 1;
                maxArea   = max(maxArea, width * heights[pos]);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int nse = n;
            int pos = stk.top();
            stk.pop();
            int pse = stk.empty() ? -1 : stk.top();

            int width = nse - pse - 1;
            maxArea   = max(maxArea, width * heights[pos]);
        }
        return maxArea;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        // return approach_1(heights);
        return approach_2(heights);
    }
};