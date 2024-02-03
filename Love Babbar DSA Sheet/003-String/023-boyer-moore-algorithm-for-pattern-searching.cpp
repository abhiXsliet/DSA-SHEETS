// https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/



#include <bits/stdc++.h>
using namespace std;

#define No_OF_CHARS 256

void badCharHeuristic(string& pat, int m, int badMatch_table[]) {
    for (int i = 0; i < m; i++) {
        badMatch_table[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badMatch_table[pat[i]] = i;
    }
}

void search(string& txt, string& pat) {
    int m = pat.length();
    int n = txt.length();

    int badMatch_table[No_OF_CHARS];

    badCharHeuristic(pat, m, badMatch_table);

    // s is shift of pattern wrt text
    int s = 0;

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j]) {
            j --;
        }

        if (j < 0) {
            cout << "Pattern occurs at shift : " << s << endl;

            // Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern. 
            // The condition s+m < n is necessary for the case when pattern occurs at the end of text.
            s += (s + m < n) ? m - badMatch_table[txt[s + m]] : 1;
        }
        else {
            
            // Shift the pattern so that the bad character in text aligns with the last occurrence of it in pattern. 
            // The max function is used to make sure that we get a positive shift. 
            // We may get a negative shift,
            // if the last occurrence of bad character in pattern is on the right side of the current character.
            s += max(1, j - badMatch_table[txt[s + j]]);
        }
    }
}

int main() {
    string txt= "ABAAABCD"; 
    string pat = "ABC"; 
    search(txt, pat); 
    return 0; 
}