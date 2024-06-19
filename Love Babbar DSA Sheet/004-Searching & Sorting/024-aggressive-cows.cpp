// https://www.spoj.com/problems/AGGRCOW/



#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(1)
bool isPossibleToPlace(vector<int>& stalls, int mid, int totalCows) {
    int cntCows    = 1;
    int lastPlaced = stalls[0];
    for (int i = 1; i < stalls.size(); i ++) {
        if (stalls[i] - lastPlaced >= mid) {
            cntCows++;
            lastPlaced = stalls[i];
        }
    }
    return cntCows >= totalCows;
}

// TC : O(N*log(max-range)) Where N = No. of stalls & Max-Range = Max. element - Min. element
// SC : O(1)
int solve(vector<int>& stalls, int n, int totalCows) {
    sort(begin(stalls), end(stalls));
    int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (isPossibleToPlace(stalls, mid, totalCows)) {
            ans  = mid;
            low  = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> stalls(n, 0);
        for (int i = 0; i < n; i ++) {
            cin >> stalls[i];
        }

        int ans = solve(stalls, n, s);
        cout << ans << endl;
    }
    return 0;
}