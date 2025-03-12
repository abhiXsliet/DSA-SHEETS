// https://www.naukri.com/code360/problems/min-heap_4691801




#include <bits/stdc++.h> 
using namespace std;

// TC : O(log(N))
// SC : O(log(N)) space used by recursive stack
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left     = 2 * i + 1;
    int right    = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) 
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

// TC : O(log(N))
// SC : O(1)
void insertIntoHeap(vector<int>& arr, int element) {
    arr.push_back(element);
    int idx = arr.size() - 1;

    // Bubble up the element to maintain heap property
    while (idx != 0 && arr[(idx - 1) / 2] > arr[idx]) {
        swap(arr[(idx - 1) / 2], arr[idx]);
        idx = (idx - 1) / 2;
    }
}

// TC : O(log(N))
// SC : O(log(N)) recursive stack space
void deleteFromHeap(vector<int>& arr) {
    if (arr.size() == 0) 
        return;

    arr[0] = arr.back();
    arr.pop_back();

    heapify(arr, arr.size(), 0);
}

// TC : O(m * log(N)) where m = q.size()
// SC : O(n) to build heap array
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> result;
    vector<int> min_heap;
    for (vector<int>& query : q) {
        if (query.size() == 1) {
            result.push_back(min_heap[0]);
            deleteFromHeap(min_heap);
        } else {
            insertIntoHeap(min_heap, query[1]);
        }
    }
    return result;
}