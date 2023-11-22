// https://leetcode.com/problems/count-and-say/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string solve(string& str) {
        int n = str.length();
        string result;

        // take first character as the prev and its count as 1
        char prev = str[0];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (str[i] == prev) {
                count++;
            }
            else {
                result += to_string(count);
                result += prev;

                // update previous char
                prev  = str[i];
                count = 1;
            }
        }

        result += to_string(count);
        result += prev;

        return result;
    }

    // TC = O(N * N)
    // SC = O(N)
    string solve_way_1(int n) {
        if (n == 1) return "1";

        string str = "1";
        for (int i = 2; i <= n; i++) {
            str = solve(str);
        }
        return str;
    }

    // TC = O(N * N)
    // SC = O(N)
    string solve_way_2(int n) {
        if (n == 1) return "1";

        string result = "1";
        for (int i = 2; i <= n; i++) {
            string str = result;

            // clear the result to store the new answer string
            result = "";

            int count = 1;
            char prev = str[0];

            for (int j = 1; j < str.length(); j++) {
                if (str[j] == str[j - 1]) {
                    count++;
                }
                else {
                    result += to_string(count);
                    result += prev;

                    // update prev and its count
                    prev  = str[j];
                    count = 1; 
                }
            }

            result += to_string(count);
            result += prev;
        }
        return result;
    }
public:
    string countAndSay(int n) {
        // return solve_way_1(n);

        return solve_way_2(n);
    }
};