// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1



//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(log(N))
    // Upper bound
    int binarySearch(vector<int> &arr, int n, int tar) {
        int low = 0, high = n - 1;
        int cnt = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= tar) {
                cnt = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return cnt + 1; // return cnt of elements <= mid, so doing +1 for 1 based indexing
    }
    
    // TC : O(M*log(N))
    int countLessThanOrEqual(vector<vector<int>> &mat, int m, int n, int mid) {
        int cntNo = 0;
        for (int i = 0; i < m; i ++) {
            cntNo += binarySearch(mat[i], n, mid); // Count elements <= mid in each row
        }
        return cntNo;
    }
  public:
    // TC : O(log(max-min) * m*log(n))
    // SC : O(1)
    int median(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 1, high = 2000;
        int medianLen = (m*n) / 2;
        int medianEle = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cntEleSmaller = countLessThanOrEqual(mat, m, n, mid);
            if (cntEleSmaller <= medianLen) {   // left half has the lesser elements than required for a median
                low = mid + 1;  
            } else {    // possibly median will be in the right side
                medianEle = mid;
                high = mid - 1;
            }
        }
        return low; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends