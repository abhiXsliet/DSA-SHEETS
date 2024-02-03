// https://www.geeksforgeeks.org/problems/min-number-of-flips3210/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

// TC : O(N)
// SC : O(1)
int solve_approach_1(string s, int n) {
    int cnt_1 = 0, cnt_2 = 0;
    
    for (int i = 0; i < n; i ++) {
        
        if (i % 2 == 0 && s[i] != '0') 
            cnt_1 ++;
        
        if (i % 2 != 0 && s[i] != '1')
            cnt_2 ++;
    }
    
    int cnt_3 = 0, cnt_4 = 0;
    
    for (int i = 0; i < n; i ++) {
        
        if (i % 2 == 0 && s[i] != '1') 
            cnt_3 ++;
        
        if (i % 2 != 0 && s[i] != '0')
            cnt_4 ++;
    }
    
    return min((cnt_1 + cnt_2), (cnt_3 + cnt_4));
}

// TC : O(N)
// SC : O(1)
int solve_approach_2(string s, int n) {
    int start_with_0 = 0;
    int start_with_1 = 0;
    
    for (int i = 0; i < n; i ++) {
        
        if (i % 2 == 0) { 
            if (s[i] == '0') 
                start_with_1 ++;
            else 
                start_with_0 ++;
        }
        else {
            if (s[i] == '1') 
                start_with_1 ++;
            else 
                start_with_0 ++;
        }
    }
    
    return min(start_with_0, start_with_1);
}

int minFlips (string s)
{
    // return solve_appraoch_1(s, s.length());
    
    return solve_approach_2(s, s.length());
}