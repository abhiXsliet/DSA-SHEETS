// https://leetcode.com/problems/assign-cookies/

// NOT A DP PROBLEM!!


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(M*logM + N*logN)
    // SC : O(1)
    int approach_1(vector<int> &g, vector<int> &s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int m = g.size(), n = s.size();
        int i = 0, j = 0;

        int contentChild = 0;
        while (i < m && j < n) {
            if (g[i] <= s[j]) {
                contentChild += 1;
                i ++, j ++;
            } else {
                j ++;
            }
        }
        return contentChild;
    }
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        return approach_1(g, s);
    }
};