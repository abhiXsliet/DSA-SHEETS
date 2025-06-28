// https://leetcode.com/problems/compare-version-numbers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getTokens(string &str) {
        vector<int> token;
        istringstream ss(str);
        string s;
        while (getline(ss, s, '.')) {
            token.push_back(stoi(s));
        }
        return token;
    }

    // TC : O(v1.length() + v2.length())
    // SC : O(M + N)    size of vectors to store integers after extraction
    int approach_1(string v1, string v2) {
        vector<int> storeV1 = getTokens(v1);
        vector<int> storeV2 = getTokens(v2);

        int m = storeV1.size(), n = storeV2.size();

        for (int i = 0; i < max(m, n); i ++) {
            int a = (i < m) ? storeV1[i] : 0;
            int b = (i < n) ? storeV2[i] : 0;

            if (a < b) 
                return -1;
            else if (a > b) 
                return 1;
        }
        return 0;
    }

    // TC : O(v1.length() + v2.length())
    // SC : O(1)
    int approach_2(string &v1, string &v2) {
        int m = v1.length(), n = v2.length();
        int val1 = 0, val2 = 0;
        for (int i = 0, j = 0; i < m || j < n; i ++, j ++) {
            while (i < m && v1[i] != '.') {
                val1 = val1 * 10 + (v1[i] - '0');
                i ++;
            }
            while (j < n && v2[j] != '.') {
                val2 = val2 * 10 + (v2[j] - '0');
                j ++;
            }
            if (val1 < val2) 
                return -1;
            else if (val1 > val2) 
                return 1;
            
            val1 = val2 = 0;    // for the next integer extraction
        }
        return 0;
    }
public:
    int compareVersion(string version1, string version2) {
        // return approach_1(version1, version2);
        return approach_2(version1, version2);   // Space O(1)
    }
};