// https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    int t[1001][1001];
    
    // TC : O(N * M)
    // SC : O(N * M)
    bool mem(string& w, string& p, int i, int j) {
        if (i == w.length() && j == p.length()) return 1;
        if (i == w.length() && j  < p.length()) return 0;
        
        if (i  < w.length() && j == p.length()) {
            for (int k = i; k < w.length(); k++) {
                if (w[k] != '*') 
                    return 0;
            }
            return 1;
        }
        
        if (t[i][j] != -1) return t[i][j];
        
        if (w[i] == p[j] || w[i] == '?') {
            return t[i][j] = mem(w, p, i + 1, j + 1);
        }
        else if (w[i] == '*') {
            return t[i][j] = ((mem(w, p, i + 1, j)) || (mem(w, p, i, j + 1)));
        }
        else return t[i][j] = false;
    }
    
    // TC : O(N * M)
    // SC : O(N * M)
    bool tab(string& w, string& p) {
        int m = w.length();
        int n = p.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));
        
        t[m][n] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            bool flag = true;
            for (int k = i; k < m; k++) {
                if (w[k] != '*') 
                    flag = 0;
            }
            t[i][n] = flag;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                if (w[i] == p[j] || w[i] == '?') {
                    t[i][j] = t[i + 1][j + 1];
                }
                else if (w[i] == '*') {
                    t[i][j] = ( (t[i + 1][j]) || (t[i][j + 1]) );
                }
                else t[i][j] = false;
            }
        }
        
        return t[0][0];
    }
    
    // TC : O(N * M)
    // SC : O(M)
    bool spaceOpt(string& w, string& p) {
        int m = w.length();
        int n = p.length();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        //After analyzing base case
        prev[0] = true;

        for(int j = 1; j <= m; j ++) {
            bool flag = true;
            for(int k = 1; k <= j; k ++) {
                if(w[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                //match
                if(p[i-1] == w[j-1] || w[j-1] == '?')
                    curr[j] = prev[j-1];
                else if(w[j-1] == '*')
                    curr[j] = ( prev[j] || curr[j-1] );
                else 
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
    public:
    bool match(string wild, string pattern)
    {
        // memset(t, - 1, sizeof(t));
        // return mem(wild, pattern, 0, 0);
        
        // return tab(wild, pattern);
        
        return spaceOpt(wild, pattern);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends