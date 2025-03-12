// https://leetcode.com/problems/sliding-window-maximum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    typedef pair<int, int> P;
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<P> pq;
        vector<int> result(n - k + 1);
        int i = 0, j = 0;
        while (j < n) {
            pq.push({nums[j], j});
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }
            if (j - i + 1 == k) {
                result[i] = pq.top().first;
                i ++;
            }
            j ++;
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(K)
    vector<int> approach_2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1);
        list<int> li;
        int i = 0, j = 0;
        while (j < n) {
            while (!li.empty() && nums[li.back()] < nums[j]) {
                li.pop_back();
            }
            
            li.push_back(j);

            if (j - i + 1 == k) {
                if (li.front() < i) li.pop_front(); // list front indices is < i then pop it
                result[i] = nums[li.front()];
                i ++;
            }
            j ++;
        }
        return result;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // return approach_1(nums, k);  // using max-heap {val, index} : pop from pq until top element-idx < i
        return approach_2(nums, k);  // Using K-sized list & linear time 
    }
};