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

    // TC : O(M * log(N))
    // SC : O(1)
    bool better(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i ++) {
            int low = 0, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == tar)
                    return true;
                else if (mat[i][mid] > tar) 
                    high = mid - 1;
                else 
                    low  = mid + 1;
            }
        }
        return false;
    }

    // TC : O(log(M) * log(N))
    // SC : O(1)
    bool optimal_1(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        int st = 0, en = m - 1;
        while (st <= en) {
            int mi = st + (en - st) / 2;
            
            int low = 0, high = n - 1;
            
            while (low <= high) {
                
                int mid = low + (high - low) / 2;
                
                if (mat[mi][mid] == tar)
                    return true;
                else if (mat[mi][mid] > tar) 
                    high = mid - 1;
                else 
                    low  = mid + 1;
            }

            if (mat[mi][0] > tar)
                en = mi - 1;
            else 
                st = mi + 1;
        }
        return false;
    }

    // TC : O(log(M * N))
    // SC : O(1)
    bool optimal_2(vector<vector<int>>& mat, int tar) {
        int m = mat.size(), n = mat[0].size();
        int st = 0, en = (m * n) - 1;
        while (st <= en) {
            int mi = st + (en - st) / 2;
            
            int ro = mi / n;
            int co = mi % n;

            if (mat[ro][co] == tar) 
                return true;
            else if (mat[ro][co] > tar)
                en = mi - 1;
            else 
                st = mi + 1;
        }
        return false;
    }

    // TC : O(M + N)
    // SC : O(1)
    int optimal_3(vector<vector<int>>& mat, int tar) {
        int m = mat.size();
        int n = mat[0].size();

        int ro = m - 1;
        int co = 0;

        while (ro >= 0 && co <= n - 1) {
            if (mat[ro][co] == tar) 
                return true;
            else if (mat[ro][co] > tar) 
                ro --;
            else co ++;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return brute(matrix, target);

        // return better(matrix, target);

        // return optimal_1(matrix, target);

        // return optimal_2(matrix, target);

        return optimal_3(matrix, target);
    }
};