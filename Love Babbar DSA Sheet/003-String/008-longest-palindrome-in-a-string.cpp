// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int t[1001][1001];
    
    bool checkPalindrome(string& s, int i, int j) {
        if (i >= j) 
            return 1;

        if (t[i][j] != -1) 
            return t[i][j];

        if(s[i] == s[j])
            return t[i][j] = checkPalindrome(s, i+1, j-1);

        return t[i][j] = 0;
    }


    string solve(string& s, int i, int j) {
        int n = s.length();
        
        while (i >= 0 && j < n) {
            if (s[i] == s[j]) {
                i--, j++;
            }
            else break;
        }
        // i+1 = starting of substring
        // and j-i-1 = No. of characters
        return s.substr(i+1, j-i-1); 
    }
    
    bool isPalindrome(string& s) {
        int i = 0;
        int j = s.length() - 1;
        
        while (i < j) {
            if (s[i] != s[j]) 
                return false;
            i++, j--;
        }
        return true;
    }
    
    // TC = O(N ^ 3) -> TLE
    // SC = O(1)
    // generate all the substring
    string solve_brute(string& s) {
        int n = s.length();
        
        int len = 0;
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            string genSt = "";
            for (int j = i; j < n; j++) {
                genSt += s[j];
                
                if (isPalindrome(genSt)) {
                    if (genSt.length() > len) {
                        len = genSt.length();
                        ans = genSt;
                    }
                }
            }
        }
        
        return ans;
    }
    
    // TC = O(N ^ 2)
    // SC = O(1)
    // Approach : Expansion from center
    string solve_optimal(string& s) {
        int n = s.length();
        
        int len = 0;
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            
            string genSt_1 = solve(s, i, i); // for odd case
            if (genSt_1.length() > len) {
                len = genSt_1.length();
                ans = genSt_1;
            }
            
            string genSt_2 = solve(s, i, i+1); // for even case
            if (genSt_2.length() > len) {
                len = genSt_2.length();
                ans = genSt_2;
            }
        }
        
        return ans;
    }
    
    // TC = O(N*N)
    // SC = O(N*N)
    string solve_dp(string s, int n) {
        memset(t, -1, sizeof(t));

        int maxLen  = 0;
        int startPt = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (checkPalindrome(s, i, j)) {
                    if(j - i + 1 > maxLen) {
                        maxLen  = max(maxLen, j - i + 1);
                        startPt = i;
                    }
                }
            }
        }

        return s.substr(startPt, maxLen);
    }
    
  public:
    string longestPalin (string S) {
        // return solve_brute(S);
        
        // return solve_optimal(S);
        
        return solve_dp(S, S.length());
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends