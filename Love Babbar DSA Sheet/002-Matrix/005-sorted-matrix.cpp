// https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    // TC = O(N * N)
    // SC = O(N * N)
    vector<vector<int>> solve_approach_1(int n, vector<vector<int>>& mat) {
        vector<int> store;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                store.push_back(mat[i][j]);
            }
        }
        
        sort(begin(store), end(store));
        
        vector<vector<int>> result;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(store[cnt++]);
            }
            result.push_back(temp);
        }
        
        return result;
    }
    
    // TC = O(N * N)
    // SC = O(N)
    vector<vector<int>> solve_approach_2(int N, vector<vector<int>>& mat) {
        vector<int> store;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                store.push_back(mat[i][j]);
            }
        }
        
        sort(begin(store), end(store));
        
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = store[cnt++];
            }
        }
        
        return mat;
    }
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // return solve_approach_2(N, Mat);
        
        return solve_approach_1(N, Mat);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends