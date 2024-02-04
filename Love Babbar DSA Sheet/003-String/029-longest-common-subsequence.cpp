// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1



//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int t[1001][1001];
    // TC : O(N*M)
    // SC : O(N*M)
    int mem(string& s1, string& s2, int n, int m, int i, int j) {
        if (i == n || j == m) return 0;
        if (t[i][j] != -1) return t[i][j];
        
        int inc = 0, exc = 0;
        if (s1[i] == s2[j]) {
            inc = 1 + mem(s1, s2, n, m, i + 1, j + 1);
        }else {
            exc = max(mem(s1, s2, n, m, i + 1, j), mem(s1, s2, n, m, i, j + 1));
        }
        
        return t[i][j] = max(inc, exc);
    }
    
    // TC : O(N*M)
    // SC : O(N*M)
    int tab(string& s1, string& s2, int n, int m) {
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                
                int inc = 0, exc = 0;
                if (s1[i] == s2[j]) {
                    inc = 1 + t[i + 1][j + 1];
                }else {
                    exc = max(t[i + 1][j], t[i][j + 1]);
                }
                
                t[i][j] = max(inc, exc);
            }
        }
        return t[0][0];
    }
    
    // TC : O(N*M)
    // SC : O(M)
    int so(string& s1, string& s2, int n, int m) {
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                
                int inc = 0, exc = 0;
                if (s1[i] == s2[j]) {
                    inc = 1 + next[j + 1];
                }else {
                    exc = max(next[j], curr[j + 1]);
                }
                
                curr[j] = max(inc, exc);
            }
            next = curr;
        }
        return curr[0];
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // memset(t, -1, sizeof(t));
        // return mem(s1, s2, n, m, 0, 0);
        
        // return tab(s1, s2, n, m);
        
        return so(s1, s2, n, m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends