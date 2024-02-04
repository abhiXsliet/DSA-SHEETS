// https://www.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    // TC : O(N)
    // SC : O(N)
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]] ++;
        }
        
        int maxCnt = 0;
        int secMax = 0;
        for (auto& it : mpp) {
            if (it.second > maxCnt) {
                secMax = maxCnt;
                maxCnt = max(maxCnt, it.second);
            }
            else {
                secMax = max(secMax, it.second);
            }
        }

        for (auto& it : mpp) {
            if (it.second == secMax)
                return it.first;
        }
        return "";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends