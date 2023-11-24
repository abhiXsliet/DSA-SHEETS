// https://www.codingninjas.com/studio/problems/k-most-occurrent-numbers_625382


#include <bits/stdc++.h>
using namespace std;

// TC = O(N * log(N))
// SC = O(N)
vector<int> solve_better(vector<int>& vec, int n) {
    unordered_map<int, int> mpp;
    for (int& i: vec) 
        mpp[i]++;
    
    // push all the map elements to a vector
    vector<pair<int,int>> sorted;
    for (auto& i : mpp) {
        sorted.push_back({i});
    }

    auto cmp = [&](pair<int,int>& a, pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        else {
            return a.first > b.first;
        }
    };

    // sort the vector according to comparing operator
    sort(begin(sorted), end(sorted), cmp);

    // to find min elments of highest and lowest freq
    int minEle_maxOcc = INT_MAX;
    int minEle_minOcc = INT_MAX;

    // Initialize highes and lowest freq
    int maxOcc = INT_MIN;
    int minOcc = INT_MAX;

    for (auto& i : sorted) {
        // if two elements has the same highest freq then pick the smaller element
        if (i.first < minEle_maxOcc && i.second >= maxOcc || i.second > maxOcc) {
            maxOcc = i.second;
            minEle_maxOcc = i.first;
        }

        // if two elements has the same lowest freq then pick the smaller element
        if (i.first < minEle_minOcc && i.second <= minOcc || i.second < minOcc) {
            minOcc = i.second;
            minEle_minOcc = i.first;
        }
    }

    // push min element with highest and lowest freq
    return {minEle_maxOcc, minEle_minOcc};
}


// TC = O(N)
// SC = O(N)
vector<int> solve_optimal(vector<int>& vec, int n) {
    vector<int> result;
    unordered_map<int, int> mpp;

    for (int& i : vec) 
        mpp[i]++;

    int maxOcc = INT_MIN;
    int minOcc = INT_MAX;

    int minEle_maxOcc = INT_MAX;
    int minEle_minOcc = INT_MAX; 
    
    for (auto& it : mpp) {
        // find ele with maxOcc
        if (it.second > maxOcc) {
            maxOcc = it.second;
            minEle_maxOcc = it.first;
        }
        // if maxOcc of elements are same then choose minEle
        else if (it.second == maxOcc && it.first < minEle_maxOcc) {
            minEle_maxOcc = it.first;
        }

        // find ele with minOcc
        if (it.second < minOcc) {
            minOcc = it.second;
            minEle_minOcc = it.first;
        }
        // if minOcc of elements are same then choose minEle
        else if (it.second == minOcc && it.first < minEle_minOcc) {
            minEle_minOcc = it.first;
        }
    }

    return {minEle_maxOcc, minEle_minOcc};
}

vector<int> getFrequencies(vector<int>& v) {
    // return solve_better(v, v.size());

    return solve_optimal(v, v.size());
}