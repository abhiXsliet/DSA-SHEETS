// https://leetcode.com/problems/integer-to-roman/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(num)) ~= O(1)
    // SC : O(13)       ~= O(1)
    string way_1(int num) {
        map<int, string> mpp;   // O(13 * log(13))
        mpp.insert({1, "I"});
        mpp.insert({4, "IV"});
        mpp.insert({5, "V"});
        mpp.insert({9, "IX"});
        mpp.insert({10, "X"});
        mpp.insert({40, "XL"});
        mpp.insert({50, "L"});
        mpp.insert({90, "XC"});
        mpp.insert({100, "C"});
        mpp.insert({400, "CD"});
        mpp.insert({500, "D"});
        mpp.insert({900, "CM"});
        mpp.insert({1000, "M"});

        string result;
        for (auto it = rbegin(mpp); it != rend(mpp); it ++) {   // O(13)
            while (num >= it -> first) {    // O(log(num))
                num -= it -> first;
                result += it -> second;
            }
        }
        return result;
    }

    // TC : O(log(num)) ~= O(1)
    // SC : O(13)       ~= O(1)
    string way_2(int num) {
        vector<int> integers  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        for (int i = 0; i < romans.size(); i ++) {
            while (num >= integers[i]) {
                num -= integers[i];
                result += romans[i];    // O(log num)
            }
        }
        return result;
    }
public:
    string intToRoman(int num) {
        // return way_1(num);  // Using ordered map
        return way_2(num);  // Using string array and corresponding roman array as a map
    }
};