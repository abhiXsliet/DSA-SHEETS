// https://leetcode.com/problems/string-to-integer-atoi/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(1)
    int myAtoi(string s) {
        int n = s.length();
        int idx = 0;
        long ans = 0;
        int sign = 1;

        // skip leading spaces
        while (idx < n && s[idx] == ' ') 
            idx ++;

        // check sign after leading whitespaces
        if (idx < n && (s[idx] == '-' || s[idx] == '+')) { 
            sign = (s[idx] == '-') ? -1 : 1;
            idx ++;
        }
        
        // make answer using digits
        while (idx < n && isdigit(s[idx])) {
            ans = ans * 10 + (s[idx] - '0');
            idx ++;

            if (sign * ans > INT_MAX) return INT_MAX;
            if (sign * ans < INT_MIN) return INT_MIN;
        }

        return sign * ans;
    }
};