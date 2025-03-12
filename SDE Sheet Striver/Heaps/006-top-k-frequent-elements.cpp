// https://leetcode.com/problems/top-k-frequent-elements/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> approach_1(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<P> maxHeap;
        unordered_map<int, int> mpp;
        for (int &num : nums) {
            mpp[num] ++;
        }
        for (auto& it : mpp) {
            maxHeap.push({it.second, it.first});
        }
        vector<int> result;
        while (!maxHeap.empty() && k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }

    // TC : O(N*log(K))
    // SC : O(K)
    vector<int> approach_2(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int &num : nums) mpp[num] ++;

        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto it : mpp) {
            int ele  = it.first;
            int freq = it.second;
            pq.push({freq, ele});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> approach_3(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;  

        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0 && k > 0; i --) {
            for (int num : buckets[i]) {
                result.push_back(num);
                k --;
            }
        }
        return result;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return approach_1(nums, k);  // N*log(N)
        // return approach_2(nums, k);  // N*log(K) : slight better
        return approach_3(nums, k);  // Bucket sort
        // return approach_4(nums, k);  // Pending : Quickselect : Optimal (worst case (N^2) very rarely hits)
    }
};