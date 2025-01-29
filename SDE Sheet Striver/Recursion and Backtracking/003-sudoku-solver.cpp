// https://leetcode.com/problems/sudoku-solver/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(1)
    // SC : O(1)
    bool isValidToPlace (char val, int row, int col, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) {  
            if (board[row][i] == val) {
                return false;
            }
            if (board[i][col] == val) {
                return false;
            }
            // check in 3 * 3
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }
        return true;
    }

    // TC : O(9^(m*n))
    // SC : O(1)
    bool solve(vector<vector<char>>& board, int m, int n) {
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == '.') {
                    
                    for (char val = '1'; val <= '9'; val ++) {
                        if (isValidToPlace(val, i, j, board)) {
                           
                            board[i][j] = val;  // if valid then place the value and check if doing that returns a true otherwise remove your placement
                            if(solve(board, m, n))  // Recursively attempt to solve the rest of the board
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, board.size(), board[0].size());
    }
};