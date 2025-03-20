// https://leetcode.com/problems/minimum-falling-path-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int R, C;
    
    int solve(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp) {
        if (i == R - 1) 
            return mat[i][j];      // OR : if (i >= R) return 0; 

        if (dp[i][j] != INT_MAX) 
            return dp[i][j];
        
        int ans = INT_MAX;
        for (int val = -1; val <= 1; val ++) {
            int newJ = j + val;
            if (newJ >= 0 && newJ < C) 
                ans = min(ans, mat[i][j] + solve(mat, i + 1, newJ, dp));
        }
        return dp[i][j] = ans;
    }

    // TC : O(R * C)
    // SC : O(R * C)
    int top_down(vector<vector<int>> &mat) {
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, INT_MAX));
        int minPathSum = INT_MAX;
        for (int j = 0; j < C; j ++) {
            minPathSum = min(minPathSum, solve(mat, 0, j, dp));
        }
        return minPathSum;
    }

    // TC : O(R * C)
    // SC : O(R * C)
    int bottom_up(vector<vector<int>> &mat) {
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, INT_MAX));

        int minPathSum = INT_MAX;
        for (int i = R - 1; i >= 0; i --) {
            for (int j = C - 1; j >= 0; j --) {
                
                if (i == R - 1) {
                    dp[i][j] = mat[i][j];   // BASE CASE
                } else {
                    int ans = INT_MAX;
                    for (int val = -1; val <= 1; val ++) {
                        int newJ = j + val;
                        if (newJ >= 0 && newJ < C) 
                            ans = min(ans, mat[i][j] + dp[i + 1][newJ]);
                    }
                    dp[i][j] = ans;
                }

                if (i == 0) 
                    minPathSum = min(minPathSum, dp[i][j]); 
            }
        }
        
        // return *min_element(begin(dp[0]), end(dp[0]));   // instead of doing this track min. with a minPathSum variable
        return minPathSum; 
    }

    // TC : O(R * C)
    // SC : O(C)
    int space_optimized(vector<vector<int>> &mat) {
        vector<int> curr(C + 1, INT_MAX), prev(C + 1, INT_MAX);

        int minPathSum = INT_MAX;
        for (int i = R - 1; i >= 0; i --) {
            for (int j = C - 1; j >= 0; j --) {
                
                if (i == R - 1) {
                    curr[j] = mat[i][j];   // BASE CASE
                } else {
                    int ans = INT_MAX;
                    for (int val = -1; val <= 1; val ++) {
                        int newJ = j + val;
                        if (newJ >= 0 && newJ < C) 
                            ans = min(ans, mat[i][j] + prev[newJ]);
                    }
                    curr[j] = ans;
                }

                if (i == 0) 
                    minPathSum = min(minPathSum, curr[j]); 
            }
            prev = curr;
        }
        
        // return *min_element(begin(prev), end(prev));   // instead of doing this track min. with a minPathSum variable
        return minPathSum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        R = matrix.size(), C = matrix[0].size();

        // return top_down(matrix);
        // return bottom_up(matrix);
        return space_optimized(matrix);
    }
};