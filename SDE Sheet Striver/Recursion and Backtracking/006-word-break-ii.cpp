// https://www.naukri.com/code360/problems/983635

// https://leetcode.com/problems/word-break-ii/

// similar : https://leetcode.com/problems/extra-characters-in-a-string/


#include <bits/stdc++.h> 
using namespace std;

void solve(int i, string& s, string& word, vector<string>& result, unordered_set<string>& st) {
    if (i >= s.length()) {
        result.push_back(word);
        return;   
    }

    string genWord;
    for (int j = i; j < s.length(); j ++) {
        genWord += s[j];
        if (st.count(genWord)) {
            string newWord = word.empty() ? genWord : word + " " + genWord;
            solve(j + 1, s, newWord, result, st);
        }
    }
}

/* 
 TC : O(N * 2^N) N = Input string length and each combination can take O(N) time to construct
 SC : O(M * L) Space used by set to store all dictionary words 
  
  O(N + M*L) + O(N*2^N)  + O(N + M*L)
 I/P Space   + O/P Space + Auxiliary Space  => Total Space 
 
 */

vector<string> wordBreak(string &s, vector<string> &dictionary){
    unordered_set<string> st(begin(dictionary), end(dictionary));
    vector<string> result;
    string word;
    solve(0, s, word, result, st);
    return result;
}