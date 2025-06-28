// https://leetcode.com/problems/reverse-words-in-a-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(N)
    // SC : O(N)
    string approach_1(string &s) {
        string result;
        reverse(begin(s), end(s));
        istringstream ss(s);
        string str;
        while (getline(ss, str, ' ')) {
            reverse(begin(str), end(str));
            if (!result.empty() && !str.empty()) 
                result += " " + str;
            else 
                result += str;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    string approach_2(string &s) {
        string result;
        reverse(begin(s), end(s));
        istringstream ss(s);
        string str;
        while (ss >> str) {
            reverse(begin(str), end(str));
            if (!result.empty() && !str.empty()) 
                result += " " + str;
            else 
                result += str;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(1)
    string approach_3(string &s) {
        int n = s.length();
        reverse(begin(s), end(s));
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j ++;  // skip leading spaces
            
            i = j;  // start of word
            while (j < n && s[j] != ' ') j ++;  // get end of word

            reverse(begin(s) + i, begin(s) + j);
        }

        i = 0, j = 0;
        // remove extra spaces from front, mid, last
        while (j < n) {
            while (j < n && s[j] == ' ') j ++;  // skip leading spaces

            while (j < n && s[j] != ' ') {  // copy non space characters
                s[i ++] = s[j ++];
            }

            while (j < n && s[j] == ' ') j ++;  // skip trailing spaces

            if (j < n) s[i ++] = ' ';  // add a single space line
        }
        s.resize(i);
        return s;
    }
public:
    string reverseWords(string s) {
        // return approach_1(s);
        // return approach_2(s);
        return approach_3(s);
    }
};