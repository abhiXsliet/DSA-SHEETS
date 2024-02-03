// https://www.geeksforgeeks.org/problems/count-palindromic-subsequences/1



//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    typedef long long int ll;
    int MOD = 1e9 + 7;
    
    ll solve(string& str, int n, int i, int j, vector<vector<int>>& dp) {
        if (i > j ) return 0;
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int include = 0;
        int exclude = 0;
        if (str[i] == str[j]) {
            include = (1 + solve(str, n, i + 1, j, dp) + 
                           solve(str, n, i, j - 1, dp) ) % MOD;
        }
        else {
            exclude = (MOD + solve(str, n, i + 1, j, dp) + 
                             solve(str, n, i, j - 1, dp) - 
                             solve(str, n, i + 1, j - 1, dp) ) % MOD;
        }
        
        return dp[i][j] = (include + exclude);
    }
    
    // TC : O(N * N)
    // SC : O(N * N)
    ll solve_tab(string& str, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n ; j++) { // if i < j return 0;
                
                if (str[i] == str[j]) {
                    dp[i][j] = (1 + (dp[i + 1][j] + dp[i][j - 1])) % MOD;
                }
                else {
                    dp[i][j] = ((dp[i + 1][j] % MOD + dp[i][j - 1] % MOD) % MOD - 
                                 dp[i + 1][j - 1] % MOD + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
    
    // TC : O(N * N)
    // SC : O(N)
    ll solve_so(string& str, int n) {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1;
            for (int j = i + 1; j < n ; j++) { // if i < j return 0;
                
                if (str[i] == str[j]) {
                    curr[j] = (1 + (next[j] + curr[j - 1])) % MOD;
                }
                else {
                    curr[j] = ((next[j] % MOD + curr[j - 1] % MOD) % MOD - 
                                next[j - 1] % MOD + MOD) % MOD;
                }
            }
            next = curr;
        }
        return curr[n - 1];
    }
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
        int n = str.length();
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(str, n, 0, n - 1, dp);
        
        // return solve_tab(str, n);
        
        return solve_so(str, n);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends