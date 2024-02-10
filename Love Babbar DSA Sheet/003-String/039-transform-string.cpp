// https://www.geeksforgeeks.org/problems/transform-string5648/1



//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
    // TC : O(N)
    // SC : O(N)
    int solve_brute(string& a, string& b) {
        int m = a.length(), n = b.length();
        
        if (m != n) return -1;
        
        unordered_map<char, int> mpp;
        
        for (char& ch : a) mpp[ch] ++;
        
        for (char& ch : b) mpp[ch] --;
        
        for (auto& it : mpp) {
            if (it.second != 0) 
                return -1;
        }
        
        int i   = m - 1;
        int j   = n - 1;
        int res = 0;
        
        while (i >= 0 && j >= 0) {
            while (i >= 0 && a[i] != b[j]) {
                res ++;
                i --;
            }
            i --;
            j --;
        }
        
        return res;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(string a, string b) {
        int m = a.length(), n = b.length();
        
        if (m != n) return -1;
        
        vector<int> count(256, 0);
        
        for (char& ch : a) {
            count[ch] ++;
        }
        
        for (char& ch : b) {
            count[ch] --;
        }
        
        for (int& num : count) {
            if (num) return -1;
        }
        
        int i   = m - 1;
        int j   = n - 1;
        int res = 0;
        
        while (i >= 0 && j >= 0) {
            while (i >= 0 && a[i] != b[j]) {
                res ++;
                i --;
            }
            i --;
            j --;
        }
        
        return res;
    }
    public:
    int transform (string A, string B)
    {
        // return solve_brute(A, B);
        
        return solve_optimal(A, B);
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends