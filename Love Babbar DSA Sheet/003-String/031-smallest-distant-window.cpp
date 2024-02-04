// https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // TC : O(N)
    // SC : O(N)
    int findSubString(string s) {
        int n = s.length();
        int i = 0; 
        int j = 0;
        
        unordered_map<char, int> mpp;
        for (char& ch : s) {
            mpp[ch] ++;
        }
        
        int k = mpp.size(); // window len
        
        int mini = INT_MAX;
        mpp.clear();
        
        while (j < n) {
            mpp[s[j]] ++;
            
            while (mpp.size() == k) {
                mini = min(mini, j - i + 1);

                mpp[s[i]]--;
                if (mpp[s[i]] == 0) mpp.erase(s[i]);
                i ++;
            }
            
            j++;
        }
        
        return mini;
    }
};


//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends