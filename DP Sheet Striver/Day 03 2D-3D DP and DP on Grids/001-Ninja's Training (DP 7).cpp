// https://www.geeksforgeeks.org/problems/geeks-training/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int n;
    int dfs(vector<vector<int>>& arr, int i, int j, unordered_map<string, int> &mpp) {
        if (i == n) 
            return 0;
        
        string key = to_string(i) + ',' + to_string(j);
        if (mpp.count(key)) return mpp[key];
        
        int ans = INT_MIN;
        for (int k = 0; k < 3; k ++) {
            if (k == j) continue;
            ans = max(ans, arr[i][k] + dfs(arr, i + 1, k, mpp));
        }
        return mpp[key] = ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_1(vector<vector<int>>& arr) {
        unordered_map<string, int> mpp;
        int ans = INT_MIN;
        for (int c = 0; c < 3; c ++) {
            ans = max(ans, arr[0][c] + dfs(arr, 1, c, mpp));
        }
        return ans;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        n = arr.size();
        return approach_1(arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends