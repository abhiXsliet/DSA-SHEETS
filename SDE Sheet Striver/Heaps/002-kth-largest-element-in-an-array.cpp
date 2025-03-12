// https://leetcode.com/problems/kth-largest-element-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(K))
    // SC : O(K)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int &num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else {
                if (pq.top() < num) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
        return pq.top();
    }
};