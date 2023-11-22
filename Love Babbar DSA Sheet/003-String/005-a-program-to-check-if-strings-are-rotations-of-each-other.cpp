// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/



#include <bits/stdc++.h>
using namespace std;

// TC = O(n+n) where n is the length of s1
// SC = O(n)
bool solve_stl(string& s1, string& s2) {
    // `string::npos` represents the "not found" condition in C++ string operations.
    return ((s1 + s1).find(s2) != string::npos);
}

// TC = O(n + n)
// SC = O(1)
bool solve_iterative(string& s1, string& s2) {
    int n = s1.length();
    int m = s2.length();
    
    if (n == 1 && m == 1)
        return s1 == s2;
    
    int cnt = 0;
    
    int i = 0; int j = 0;
    
    while (i < n && j < m) {
        
        if (s1[i] == s2[j]) {
            i++, j++;
        }
        else {
            i++;
        }
        
        if (i == n) {
            i = 0;
            cnt += 1;
        }
        
        if (j == m) return true;
        
        if (cnt == 2) break;
    }
    
    return false;
}


int main() {
    string s1 = "abcd";
    string s2 = "cdab";
 
    if (s1.length() != s2.length()) {
        cout << "s2 is not a rotation on s1" << endl;
    }
    else {
        // Approach - 1
        if (solve_stl(s1, s2))
            cout << "\nStrings are rotations of each other - (Using STL)" << endl;
        else
            cout << "\nStrings are not rotations of each other" << endl;
        
        // Approach - 2
        if (solve_iterative(s1, s2))
            cout << "\nStrings are rotations of each other - (Using Iterative)" << endl;
        else
            cout << "\nStrings are not rotations of each other" << endl;
    }

    cout << endl;
    return 0;
}