// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1




//{ Driver Code Starts
// Program to find minimum number of platforms required on a railway station
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*log(N)) 
    // SC : O(N)
    int approach_1(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        vector<pair<int, char>> vec;
        for (int i = 0; i < n; i ++) {
            vec.push_back({arr[i], 'A'});
            vec.push_back({dep[i], 'D'});
        }
        
        sort(vec.begin(), vec.end());
        
        int cntMinPlatform = 0;
        int platform = 0;
        for (int i = 0; i < 2*n; i ++) {
            char ch = vec[i].second;
            
            if (ch == 'A') {
                platform ++;
            } else {
                platform --;
            }
            cntMinPlatform = max(cntMinPlatform, platform);
        }
        return cntMinPlatform;
    }

    // TC : O(N*log(N)) 
    // SC : O(1)
    int approach_2(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int cntMinPlatform = 0;
        int platform = 0;
        
        while (i < n) {
            if (arr[i] <= dep[j]) {
                platform ++;
                i ++;
            } else {
                platform --;
                j ++;
            }
            cntMinPlatform = max(cntMinPlatform, platform);
        }
        
        return cntMinPlatform;
    }
  public:
    // Function to find the minimum number of platforms required at the railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // return approach_1(arr, dep); // SIMULATION : No distortation in given input
        
        return approach_2(arr, dep); // Given Input Distorted
    }
};

//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}
// } Driver Code Ends