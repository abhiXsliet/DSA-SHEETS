// https://leetcode.com/problems/valid-parentheses/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // TC : O(N)
    // SC : O(N)
    bool isValid(string s) {
        stack<char> stk;
        for (char &ch : s) {
            if (stk.empty()) {
                stk.push(ch);
            } else {
                if (stk.top() == '(' && ch == ')' || 
                    stk.top() == '{' && ch == '}' || 
                    stk.top() == '[' && ch == ']') {
                    stk.pop();
                } else stk.push(ch);
            }
        }
        return stk.empty();
    }
};