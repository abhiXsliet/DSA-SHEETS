// https://www.geeksforgeeks.org/problems/consecutive-elements2306/1



//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        int n = s.length();
        string result;
        
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != s[i]) {
                result += s[i - 1];
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 

// } Driver Code Ends