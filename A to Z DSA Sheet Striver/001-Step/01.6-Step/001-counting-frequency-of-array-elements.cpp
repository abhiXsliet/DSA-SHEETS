// https://www.codingninjas.com/studio/problems/count-frequency-in-a-range_8365446


#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// SC = O(N)
vector<int> solve_brute(int n, int x, vector<int>& nums) {
    unordered_map<int, int> mpp; // O(1)
    vector<int> ans;

    for (int& i : nums)
        mpp[i]++;       // O(1)

    for (int i = 1; i <= n; i++)
        ans.push_back(mpp[i]);

    return ans;
}

// TC = O(N)
// SC = O(1)
vector<int> solve_optimal(int n, int x, vector<int>& nums) {
    vector<int> result(n, 0);
    for (int& i : nums)
        result[i -1]++;
    return result;
}
vector<int> countFrequency(int n, int x, vector<int> &nums){
    // return solve_brute(n, x, nums);

    return solve_optimal(n, x, nums);
}
