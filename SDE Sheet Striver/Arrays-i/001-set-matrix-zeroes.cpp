// https://leetcode.com/problems/set-matrix-zeroes/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void markRowZero(vector<vector<int>>& mat, int n, int i) {
        for (int j = 0; j < n; j ++) {
            if (mat[i][j] != 0) {
                mat[i][j] = 1e9 + 7;
            }
        }
    }

    void markColZero(vector<vector<int>>& mat, int m, int j) {
        for (int i = 0; i < m; i ++) {
            if (mat[i][j] != 0) {
                mat[i][j] = 1e9 + 7;
            }
        }
    }

    // TC : O((M * N) * (M + N)) + O(M + N)
    // SC : O(1)
    void brute(vector<vector<int>>& mat, int m, int n) {
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    markRowZero(mat, n, i);
                    markColZero(mat, m, j);
                }
            }
        }

        // iterate one more time to set 1e9+7 as 0 in matrix
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 1e9 + 7) {
                    mat[i][j] = 0;
                }
            }
        }
    }

    // TC : O(M * N)
    // SC : O(M + N)
    void better(vector<vector<int>>& mat, int m, int n) {
        vector<int> rowStore(m, 0);
        vector<int> colStore(n, 0);

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    rowStore[i] = 1;    // mark ith row
                    colStore[j] = 1;    // mark jth col
                }
            }
        }

        // iterate one more time to set stored rows and cols as 0
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (rowStore[i] || colStore[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }

    // TC : O(M * N)
    // SC : O(1)
    void optimal(vector<vector<int>>& mat, int m, int n) {
        // vector<int> rowStore(m, 0);  // mat[...][0]
        // vector<int> colStore(n, 0);  // mat[0][...] 

        int col0 = 1;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;   // mark ith row
                    if (j != 0)
                        mat[0][j] = 0;   // mark jth col
                    else 
                        col0 = 0;
                }
            }
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // finally mark all cells of the first row 
        if (mat[0][0] == 0) {
            for (int j = 0; j < n; j ++) {
                mat[0][j] = 0;
            }
        }
        
        // finallly mark all the cells of the first col
        if (col0 == 0) {
            for (int i = 0; i < m; i ++) {
                mat[i][0] = 0;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute(matrix, matrix.size(), matrix[0].size());
        // better(matrix, matrix.size(), matrix[0].size());
        optimal(matrix, matrix.size(), matrix[0].size());
    }
};