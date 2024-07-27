// https://leetcode.com/problems/pascals-triangle-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    long long getNCR(int row, int col) {
        long long ans = 1;
        for (int i = 0; i < col; i++) {
            ans = ans * (row - i);
            ans = ans / (i + 1);
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(1)
    vector<int> brute(int row) {
        vector<int> ans(row + 1, 1);
        for (int i = 1; i <= row-1; i++) {
            ans[i] = getNCR(row, i);
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    vector<int> brute_2(int row) {
        vector<vector<int>> store(row + 1);
        for (int i = 0; i <= row; i++) {
            store[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                store[i][j] = store[i - 1][j] + store[i - 1][j - 1];
            }
        }
        return store[row];
    }

    // TC : O(N^2)
    // SC : O(1)
    vector<int> better(int row) {
        vector<int> prev;
        for (int i = 0; i <= row; i++) {
            vector<int> curr(i + 1, 1);
            for (int j = 1; j < i; j++) {
                curr[j] = prev[j] + prev[j - 1];
            }
            prev = curr;
        }
        return prev;
    }

    // TC : O(N)
    // SC : O(1)
    vector<int> optimal(int row) {
        vector<int> result(row + 1, 1);
        long long val = 1;
        for (int i = 1; i <= row-1; i++) {
            val *= (row - (i - 1));
            val /= i;
            result[i] = val;
        }
        return result;
    }
public:
    vector<int> getRow(int rowIndex) {
        // return brute(rowIndex);

        // return brute_2(rowIndex);    // Generate Pascal Triangle & return (rowIndex - 1)

        // return better(rowIndex);     // Reduced space by using a prev and curr vector

        // return optimal(rowIndex);
    }
};