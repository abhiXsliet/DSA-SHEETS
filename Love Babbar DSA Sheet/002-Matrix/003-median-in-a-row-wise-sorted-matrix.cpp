// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    // TC = O(log(m))
    int upper_bound (vector<int>& mat, int val, int m) {
        int low  = 0;
        int high = m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[mid] > val) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return low;
    }
    
    // TC = O(row * log(col)) -> O(n * log(m)) where n = rows, m = cols
    int getNoOfNos(vector<vector<int>>& mat, int n, int m, int val) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upper_bound(mat[i], val, m);
        }
        return cnt;
    }
public:
    // TC = O(log(1e9) * nlog(m)) -> TC(BS * upperBound)
    int median(vector<vector<int>> &matrix, int R, int C){
        int low  = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < R; i++) {
            low = min(low, matrix[i][0]);
            
            high = max(high, matrix[i][C-1]);
        }
        
        int median_idx = (R * C) / 2;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // count numbers of no. 
            // nosOfNo is the how many no. is less than or equal to that no. 
            int noOfNos_mid  = getNoOfNos(matrix, R, C, mid);
            
            if (noOfNos_mid <= median_idx) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends