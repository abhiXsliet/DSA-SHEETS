// https://leetcode.com/problems/rotate-image/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(M^2 + M*N)
    // SC : O(1)
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j <= i; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < m; i ++) {
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};