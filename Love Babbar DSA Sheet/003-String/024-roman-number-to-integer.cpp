// https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1




//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int romanToDecimal(string &str) {
        int n = str.length();
        
        unordered_map<char, int> mpp {
                                        {'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}
                                     };
                                     
        int result = mpp[str.back()];
        
        for (int i = 0; i < n - 1; i ++) {
            
            if (mpp[str[i]] < mpp[str[i + 1]]) {
                result -= mpp[str[i]];
            }
            else {
                result += mpp[str[i]];
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends