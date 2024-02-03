// https://www.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    vector<vector<int>> directions {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    // TC : O(4^T) Where T = Length Of Target String
    int solve(vector<vector<char>>& mat, string& target, int i, int j, int idx) {
        int found = 0;
        
        if (i < mat.size() && i >= 0 && j < mat[0].size() && j >= 0 && target[idx] == mat[i][j]) {
            
            mat[i][j] = '#'; // visited
            
            if (idx == target.length() - 1) 
                found = 1;
            else {
                for (auto& dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    
                    found += solve(mat, target, i_, j_, idx + 1);
                }
            }
            
            // backtrack
            mat[i][j] = target[idx];
        }
        
        return found;
    }
    public:
    // TC : O((N*M) * 4^T) Where N = Row && M = Cols && T = Length Of Target String
    // SC : O(1)
    int findOccurrence(vector<vector<char> > &mat, string target){
        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                
                res += solve(mat, target, i, j, 0);
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends