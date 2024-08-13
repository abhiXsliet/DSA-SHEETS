// https://leetcode.com/problems/longest-consecutive-sequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool linearSearch(int tar, vector<int>& nums) {
        for (int num : nums)
            if (num == tar) return true;

        return false;
    }

    // TC = O(N^2)
    // SC = O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return 0;

        int maxCnt = 1;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int cnt = 0;
            
            while(linearSearch(curr, nums)) {
                cnt ++;
                curr ++;
            }
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }

    // TC = O(N*log(N))
    // SC = O(1)
    int better(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(begin(nums), end(nums));

        int maxCnt = 1;
        int prev = nums[0];
        int cnt  = 1;

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (prev + 1 == curr)  cnt ++;
            else if (curr != prev) cnt = 1;
            prev = curr;
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }

    // TC = O(N)
    // SC = O(N)
    int optimal(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        st.insert(begin(nums), end(nums));

        int maxCnt = 0;
        for (int curr : st) {
            int cnt = 1;
            // If prev is not present in set
            if (st.find(curr - 1) == st.end()) { // without condition : TLE
                // We serach for the next of curr to make a chain of LCS
                while(st.find(curr + 1) != st.end()) {
                    curr ++;
                    cnt ++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        // return brute(nums);

        // return better(nums);

        return optimal(nums);
    }
};