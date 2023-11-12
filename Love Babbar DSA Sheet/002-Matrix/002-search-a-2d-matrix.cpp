// https://leetcode.com/problems/search-a-2d-matrix/


#include <bits/stdc++.h>
using namespace std;    

class Solution {
private:
    // TC = O(N*M)
    // SC = O(1)
    bool solve_brute(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == target) return true;
            }
        }

        return false;
    }

    // TC = O(N + M)
    // SC = O(1)
    int solve_better(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = n - 1;
        int col = 0;

        while (row >= 0 && col <= m - 1) {
            if (matrix[row][col] > target) {
                row--;
            }
            else if (matrix[row][col] < target) {
                col++;
            }
            else return true;
        }
        return false;
    }

    // TC = O(log(n*m))
    // SC = O(1)
    bool solve_optimal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; 
        int high = n*m - 1;
        int pass = 1;
        while (low <= high) {
            int mid = low + ( high - low )/2;

            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return solve_brute(matrix, target);

        return solve_better(matrix, target);

        return solve_optimal(matrix, target);
    }
};