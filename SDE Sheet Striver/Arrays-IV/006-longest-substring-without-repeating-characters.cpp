// https://leetcode.com/problems/longest-substring-without-repeating-characters/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int optimal(string s) {
        int n = s.length();
        vector<int> freq(256, 0);

        int i = 0, j = 0;
        int maxL = 0;

        while (j < n) {
            freq[s[j]] ++;

            while (freq[s[j]] > 1) {
                freq[s[i]] --;
                i ++;
            }

            maxL = max(maxL, j - i + 1);

            j ++;
        }
        return maxL;
    }
public:
    int lengthOfLongestSubstring(string s) {
        // Brute : O(N^2) two loops
        
        return optimal(s);
    }
};