// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> stEnd;
        for (int i = 0; i < n; i ++) {
            stEnd.push_back({end[i], start[i]});
        }
        
        sort(stEnd.begin(), stEnd.end());
        
        int result    = 0;
        int maxEnTime = 0;
        for (int i = 0; i < n; i ++) {
            int endT   = stEnd[i].first;
            int startT = stEnd[i].second;
            if (startT > maxEnTime) {
                result ++;
                maxEnTime = endT;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends