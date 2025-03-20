// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

// similar problem : https://www.leetcode.com/problems/cherry-pickup-ii/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int R;  // rows
    int C;  // cols
    int top_down(vector<vector<int>> &grid, int row, int c1, int c2, vector<vector<vector<int>>> &dp) {
        if (row >= R) 
            return 0; 
        
        if (dp[row][c1][c2] != -1) 
            return dp[row][c1][c2];
            
        int chocolate = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];    
        
        int ans = 0;
        for (int v1 = -1; v1 <= 1; v1 ++) { // Robot - 1 has 3 options
            for (int v2 = -1; v2 <= 1; v2 ++) { // Robot - 2 has 3 options for each of robot-1
                
                int newC1 = c1 + v1;    // newCol for robot-1
                int newC2 = c2 + v2;    // newCol for robot-2
                
                if (newC1 >= 0 && newC1 < C && newC2 >= 0 && newC2 < C)
                    ans = max(ans, top_down(grid, row + 1, newC1, newC2, dp));
            }
        }
        return dp[row][c1][c2] = chocolate + ans;
    }
    
    // TC : O(M * N * N)
    // SC : O(M * N * N)
    int approach_1(vector<vector<int>> &grid) {
        vector<vector<vector<int>>> dp(R + 1, vector<vector<int>>(C + 1, vector<int>(C + 1, -1)));
        return top_down(grid, 0, 0, C - 1, dp);
    }
    
    // TC : O(M * N * N)
    // SC : O(M * N * N)
    int approach_2(vector<vector<int>> &grid) {
        vector<vector<vector<int>>> dp(R + 1, vector<vector<int>>(C + 1, vector<int>(C + 1, 0)));
        
        for (int row = R - 1; row >= 0; row --) {
            for (int c1 = C - 1; c1 >= 0; c1 --) {
                for (int c2 = 0; c2 < C; c2 ++) {
                    
                    int chocolate = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];    
        
                    int ans = 0;
                    for (int v1 = -1; v1 <= 1; v1 ++) { // Robot - 1 has 3 options
                        for (int v2 = -1; v2 <= 1; v2 ++) { // Robot - 2 has 3 options for each of robot-1
                            
                            int newC1 = c1 + v1;    // newCol for robot-1
                            int newC2 = c2 + v2;    // newCol for robot-2
                            
                            if (newC1 >= 0 && newC1 < C && newC2 >= 0 && newC2 < C)
                                ans = max(ans, dp[row + 1][newC1][newC2]);
                        }
                    }
                    dp[row][c1][c2] = chocolate + ans;
                }
            }
        }
        
        return dp[0][0][C - 1];
    }
    
    // TC : O(M * N * N)
    // SC : O(N * N)
    int approach_3(vector<vector<int>> &grid) {
        vector<vector<int>> curr(C + 1, vector<int>(C + 1, 0));
        vector<vector<int>> prev(C + 1, vector<int>(C + 1, 0));
        
        for (int row = R - 1; row >= 0; row --) {
            for (int c1 = C - 1; c1 >= 0; c1 --) {
                for (int c2 = 0; c2 < C; c2 ++) {
                    
                    int chocolate = (c1 == c2) ? grid[row][c1] : grid[row][c1] + grid[row][c2];    
        
                    int ans = 0;
                    for (int v1 = -1; v1 <= 1; v1 ++) { // Robot - 1 has 3 options
                        for (int v2 = -1; v2 <= 1; v2 ++) { // Robot - 2 has 3 options for each of robot-1
                            
                            int newC1 = c1 + v1;    // newCol for robot-1
                            int newC2 = c2 + v2;    // newCol for robot-2
                            
                            if (newC1 >= 0 && newC1 < C && newC2 >= 0 && newC2 < C)
                                ans = max(ans, prev[newC1][newC2]);
                        }
                    }
                    curr[c1][c2] = chocolate + ans;
                }
            }
            prev = curr;
        }
        
        return prev[0][C - 1];
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        R = n;
        C = m;
        // return approach_1(grid);
        // return approach_2(grid);
        return approach_3(grid);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends