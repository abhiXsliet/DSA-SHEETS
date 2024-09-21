// https://leetcode.com/problems/assign-cookies/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(max{N*log(N) + M*log(M)}) Where N = size of greed array and M = size of cookie array
    // SC : O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, cnt = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};