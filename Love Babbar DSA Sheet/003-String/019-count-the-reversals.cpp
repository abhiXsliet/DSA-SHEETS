// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

// TC : O(N)
// SC : O(N)
int solve_approach_1(string s, int n) {
    if (n % 2 != 0) return -1;
    
    stack<char> stk;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '{') {
            stk.push(s[i]);
        }
        else {
            if (stk.empty()) {
                cnt ++;
                stk.push('{');
            }
            else {
                stk.pop();
            }
        }
    }
    
    return cnt + (stk.size() / 2);
}

// TC : O(N)
// SC : O(1)
int solve_approach_2(string s, int n) {
    if (n % 2 != 0) return -1;
    
    int openBrac  = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '{') {
            openBrac ++;
        }
        else {
            if (openBrac == 0) {
                cnt ++;
                openBrac ++;
            }
            else {
                openBrac --;
            }
        }
    }
    
    return cnt + (openBrac / 2);
}

int countRev (string s)
{
    // return solve_approach_1(s, s.length());
    
    return solve_approach_2(s, s.length());
}