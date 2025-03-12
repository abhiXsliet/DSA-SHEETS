// https://leetcode.com/problems/find-median-from-data-stream/




#include <bits/stdc++.h>
using namespace std;
// TC : O(N*log(N)) Where N = No. of elments getting pushed/popped
// SC : O(N)
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // maxHeap could only have atmost +1 more element or equal compared to minHeap
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {   // at max minHeap size can be equal to maxHeap not more than that
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) { // even no of elements so, median is (maxHeap.top() + minHeap.top())/2
            double mean = ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
            return mean;
        }
        // odd no of elements so, median is maxHeap.top()
        return (double) maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */