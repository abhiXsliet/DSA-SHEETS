// https://leetcode.com/problems/roman-to-integer/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(string &s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        mpp.insert({'I', 1});
        mpp.insert({'V', 5});
        mpp.insert({'X', 10});
        mpp.insert({'L', 50});
        mpp.insert({'C', 100});
        mpp.insert({'D', 500});
        mpp.insert({'M', 1000});

        int result = 0;
        for (int i = 0; i < n; i ++) {
            if (i + 1 < n && mpp[s[i]] < mpp[s[i + 1]]) {
                result -= mpp[s[i]];
            } else {
                result += mpp[s[i]];
            }
        }
        return result;
    }
public:
    int romanToInt(string s) {
        return approach_1(s);
    }
};