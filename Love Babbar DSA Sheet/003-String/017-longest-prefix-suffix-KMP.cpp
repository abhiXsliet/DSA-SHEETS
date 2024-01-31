// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1



//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  private:
    // TC : O(N)
    // SC : O(N)
    int solve(string& s, int n) {
        vector<int> storePrefix(n, 0);
        
        for (int i = 1; i < n; i++) {
            int j = storePrefix[i - 1];
            
            while (j > 0 && s[i] != s[j]) {
                j = storePrefix[j - 1];
            }
            
            if (s[i] == s[j]) {
                j ++;
            }
            
            storePrefix[i] = j;
        }
        
        return storePrefix[n - 1];
    }
  public:		
	int lps(string s) {
	    return solve(s, s.length());
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends