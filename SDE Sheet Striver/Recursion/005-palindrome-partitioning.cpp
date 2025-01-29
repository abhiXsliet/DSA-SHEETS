// https://leetcode.com/problems/palindrome-partitioning/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(string str) {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i ++, j --;
        }
        return true;
    }
    
/*     Time Complexity: O(2^N * N/2 * K)
      - O(2^N): Generates every possible substring,
        where N is the length of the input string.
      - O(N/2): Checks if each substring is a palindrome.
      - O(K)  : Inserts palindromes into the data structure,
        where K is the average length of the palindrome list.
        
    Space Complexity: O(K * X + N)
      - O(K * X): Stores the list of palindromes in the result,
        where K is the average length of each palindrome and X is the total number of palindrome lists.
      - O(N): Recursive space used by the call stack,
        which can go up to N in depth due to the nature of the recursion.
*/
    void solve(string s, int idx, vector<string>& store, vector<vector<string>>& res) {
        if (idx >= s.length()) {
            res.push_back(store);
            return;
        }

        string str;
        for (int i = idx; i < s.length(); i ++) {
            str += s[i];

            if (isPalindrome(str)) {
                store.push_back(str);
                solve(s, i + 1, store, res);
                store.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> store;
        solve(s, 0, store, result);
        return result;
    }
};