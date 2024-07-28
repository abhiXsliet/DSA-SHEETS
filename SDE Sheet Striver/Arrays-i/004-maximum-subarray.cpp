// https://leetcode.com/problems/maximum-subarray/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxSumCenter(vector<int>& nums, int l, int mid, int h) {
        int left_sum = INT_MIN;
        int sum = 0;
        for(int i = mid; i >= l; i--) {
            sum += nums[i];
            if(sum > left_sum) left_sum = sum;
        }

        int right_sum = INT_MIN;
        sum = 0;
        for(int i = mid; i <= h; i++) {
            sum += nums[i];
            if(sum > right_sum) right_sum = sum;
        }

        return max( left_sum + right_sum - nums[mid], max(left_sum, right_sum) );
    }

    // TC : O(N^3)
    // SC : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                int sum = 0;
                for (int k = i; k <= j; k ++) {
                    sum += nums[k];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // TC : O(N^2)
    // SC : O(1)
    int better(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i ++) {
            int sum = 0;
            for (int j = i; j < n; j ++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    // TC : O(N)
    // SC : O(1)
    int optimal(vector<int>& nums) {
        int sum  = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > maxi) maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        return maxi; 
    }   

    // TC : O(N)
    // SC : O(1)
    int followUp(vector<int>& nums) {
        int sum    = 0;
        int maxi   = INT_MIN;
        int ansS   = -1;
        int ansE   = -1;
        int start  = -1;
        for(int i = 0; i < nums.size(); i++) {
            if (sum == 0) start = i;
            sum += nums[i];
            if(sum > maxi) {
                maxi = max(maxi, sum);
                ansS = start;
                ansE = i;
            }
            if(sum < 0) sum = 0;
        }
        for (int i = ansS; i <= ansE; i ++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return maxi; 
    }   

    // TC : O(N * log(N))
    // SC : O(N) -> recursive depth
    int rec(vector<int>& nums, int l, int h) {
        if(l > h) return INT_MIN;
        if(l == h) return nums[l];

        int mid = l + (h - l)/2;
        return max( max(rec(nums, l, mid - 1), 
                        rec(nums, mid + 1, h) ), 
                        maxSumCenter(nums, l, mid,  h) );
    }
public:
    int maxSubArray(vector<int>& nums) {
        // return brute(nums);
        // return better(nums);
        // return optimal(nums);   // KADANE's
        return followUp(nums);  // Follow Up : print the maxSum Subarray
        // return rec(nums, 0, nums.size() - 1); // Recursion
    }
};