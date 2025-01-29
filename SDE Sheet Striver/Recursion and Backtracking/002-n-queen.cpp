// https://leetcode.com/problems/n-queens/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N!)
    // SC : O(N) Recursive Stack Space
    void solve_optimized(int row, int n, vector<string>& board, vector<vector<string>>& result, unordered_set<int>& cols, unordered_set<int>& rDiag, unordered_set<int>& lDiag) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col ++) {
            if (!cols.count(col) && !rDiag.count(row + col) && !lDiag.count(row - col)) {
                board[row][col] = 'Q';
                
                cols.insert(col);           // mark the occupancy of col
                rDiag.insert(row + col);    // mark the occupancy of right diagonal (i.e., upward right row + col)
                lDiag.insert(row - col);    // mark the occupancy of right diagonal (i.e., upward left  row - col)

                solve_optimized(row + 1, n, board, result, cols, rDiag, lDiag);
                board[row][col] = '.';

                cols.erase(col);        // remove the occupancy from set while backtracking
                rDiag.erase(row + col);
                lDiag.erase(row - col); 
            }
        }
    }

    // TC : O(N) for each call
    // SC : O(1)
    bool isSafe(int row, int col, int n, vector<string>& board) {
        // attack from upward
        for (int r = 0; r < row; r ++) {
            if (board[r][col] == 'Q') {
                return false;
            }
        }

        // attack from leftward
        for (int c = 0; c < col; c ++) {
            if (board[row][c] == 'Q') {
                return false;
            }
        }

        // attack from upward-left
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r --, c --) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }

        // attack from upward right
        for (int r = row - 1, c = col + 1; r >= 0 && c < n; r --, c ++) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // TC : O(N!)
    // SC : O(N) Recursive Stack Space
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col ++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }

    // TC : O(N!)
    // SC : O(N) due to the use of sets for columns and diagonals
    vector<vector<string>> approach_1(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, result);
        return result; 
    }

    // TC : O(N!)
    // SC : O(1) No extra space used 
    vector<vector<string>> approach_2(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        // Track occupied columns and upward rightDiagonal and upward leftDiagonal 
        unordered_set<int> columnInUse, rightDiagonals, leftDiagonals;  
        
        solve_optimized(0, n, board, result, columnInUse, rightDiagonals, leftDiagonals);
        return result; 
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // return approach_1(n);  

        return approach_2(n);   // Optimized isSafe fn using three different sets
    }
};