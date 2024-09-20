// https://leetcode.com/problems/trapping-rain-water/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N * N)
    // SC = O(1)
    int brute(vector<int>& arr, int n) {
        int maxWater = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = arr[i];
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, arr[j]);
            }

            int rightMax = arr[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }

            maxWater += min(leftMax, rightMax) - arr[i];
        }
        return maxWater;
    }

    // TC = O(N)
    // SC = O(N)
    int better(vector<int>& arr, int n) {
        vector<int> leftMax(n,  arr[0]);     // prefix
        vector<int> rightMax(n, arr[n - 1]); // suffix

        for (int i = 1; i < n; i++) {
            leftMax[i]          = max(leftMax[i - 1], arr[i]);
            rightMax[n - i - 1] = max(rightMax[n - i], arr[n - i - 1]);
        }

        int maxWater = 0;
        for (int i = 0; i < n; i++) {
            maxWater += min(leftMax[i], rightMax[i]) - arr[i];
        }
        return maxWater;
    }

    // TC = O(N)
    // SC = O(1)
    int optimal(vector<int>& arr, int n) {
        int i = 0, j = n - 1;
        
        int maxLeft  = 0;
        int maxRight = 0;
        int maxWater = 0;

        while (i <= j) {
            if (arr[i] <= arr[j]) {
                if (maxLeft <= arr[i]) {
                    maxLeft = arr[i];
                } else {
                    maxWater += (maxLeft - arr[i]);
                }
                i ++;
            } else {
                if (maxRight <= arr[j]) {
                    maxRight = arr[j];
                } else {
                    maxWater += (maxRight - arr[j]);
                }
                j --;
            }
        }

        return maxWater;
    }
public:
    int trap(vector<int>& height) {
        // return brute(height, height.size());     // O(N^2) : for every i, get leftMax till (i) and rightMax from (i+1) to (n-1)

        // return better(height, height.size());    // Prefix/Suffix Array

        return optimal(height, height.size());   // Two Pointer Approach
    }
};