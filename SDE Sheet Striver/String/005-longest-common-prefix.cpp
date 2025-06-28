// https://leetcode.com/problems/longest-common-prefix/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int getShortestIdx(vector<string> &strs) {
        int minLen = INT_MAX, minIdx = -1;
        for (int i = 0; i < strs.size(); i ++) {
            if (minLen > strs[i].length()) {
                minLen = strs[i].length();
                minIdx = i;
            }
        }
        return minIdx;
    }

    // TC : O(M*N) M = length of first string and N = size of vector
    // SC : O(M)
    string approach_1(vector<string>& strs) {
        int n = strs.size();
        string lcp;
        string first = strs[0];
        bool isEqual = 1;
        int idx = 0;
        while (idx < first.length()) {
            for (int j = 1; j < n; j ++) {
                string second = strs[j];
                if (idx >= second.length() || 
                    (idx < second.length() && idx < first.length() && second[idx] != first[idx])) {
                    isEqual = 0;
                    break;
                }
            }
            if (isEqual) lcp += first[idx];
            idx ++;
        }
        return lcp;
    }

    // TC : O(M*N) M = length of shortest string and N = size of vector
    // SC : O(1)
    string approach_2(vector<string>& strs) {
        int n = strs.size();
        int shortIdx = getShortestIdx(strs);

        while (strs[shortIdx].length()) {
            int count = 0;
            for (int i = 0; i < n; i ++) {
                if (strs[i].find(strs[shortIdx]) == 0) {    // if strs[shortIdx] is available as prefix
                    count ++;
                }
            }
            if (count == n) {
                return strs[shortIdx];
            }
            strs[shortIdx].pop_back();  // remove the last char and again recheck in all strings
        }
        return strs[shortIdx];
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // return approach_1(strs);     // NAIVE
        return approach_2(strs);     // Optimal : Modify the shortest string by poping it from back and return it
    }
};