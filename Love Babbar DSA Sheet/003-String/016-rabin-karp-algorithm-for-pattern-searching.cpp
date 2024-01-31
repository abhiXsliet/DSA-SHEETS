// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

// PROBLEM LINK:
// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
// no. of characters in the input alphabets
#define d 256

vector<int> search_pattern(char text[], char pattern[]) {

    int m = strlen(pattern);  // Length of pattern
    int n = strlen(text);     // Length of text

    int pHash = 0;   // hash value for pattern
    int tHash = 0;   // hash value for text

    int h = 1;

    // The value of h would be : pow(d, m - 1);
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % MOD;
    }

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % MOD;
        tHash = (d * tHash + text[i]) % MOD;
    }

    vector<int> ans;

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        
        int j;

        // Check for characters one by one
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
    
        if (j == m) {
            ans.push_back(i);
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % MOD;

            // We might get negative value of t, converting it to positive
            if (tHash < 0) {
                tHash += MOD;
            }
        }
    }
    return ans;
}

int main() {
    char txt[]  = "geeksforgeeks";
    char patt[] = "geeks";

    vector<int> result = search_pattern(txt, patt);
    cout << "String Found At Indices : " << endl;
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}