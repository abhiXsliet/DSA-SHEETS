// https://www.geeksforgeeks.org/problems/subset-sums2234/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(2^N)
    // SC : O(N) : Recursive Stack Space 
    void solve(vector<int>& arr, int n, int idx, int sum, vector<int>& res) {
        if (idx >= n) {
            res.push_back(sum);
            return;
        }
        
        sum += arr[idx];            // Take & explore next
        solve(arr, n, idx + 1, sum, res);
        sum -= arr[idx];            // Not Take & explore next
        solve(arr, n, idx + 1, sum, res);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> result;
        solve(arr, n, 0, 0, result);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends