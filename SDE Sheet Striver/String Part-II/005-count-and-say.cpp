// https://leetcode.com/problems/count-and-say/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string countAndSay(string &s) {
        int n = s.length();
        char prev = s[0];
        int count = 1;
        string res;
        for (int i = 0; i < n; i ++) {
            if (i == n - 1) {
                res += (to_string(count) + prev);
            } else if (i + 1 < n && s[i] == s[i + 1]) {
                count ++;
            } else {
                res += (to_string(count) + prev);
                if (i + 1 < n) {
                    count = 1;
                    prev = s[i + 1];
                }
            }
        }
        return res;
    }

    // TC : O(N * Len)
    // SC : O(N + Len) N = Recursive Stack Space and Len = longest sequence formed by countAndSay fn.
    string approach_1(int n) {
        if (n == 1) return "1";

        string res = approach_1(n - 1);
        return countAndSay(res);
    }

    // TC : O(N * Len)
    // SC : O(Len)
    string approach_2(int n) {
        string base = "1";
        while (n -- > 1) {
            string countS = countAndSay(base);
            base = countS;
        }
        return base;
    }
public:
    string countAndSay(int n) {
        // return approach_1(n);    // Recursively
        return approach_2(n);    // Iteratively
    }
};