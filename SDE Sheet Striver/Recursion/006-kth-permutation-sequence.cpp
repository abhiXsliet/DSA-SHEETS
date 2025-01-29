// https://leetcode.com/problems/permutation-sequence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N * N!) ~= O(N!) No. of permutations of a string of length 'N' is 'N!'
    //                         Each permutation takes O(N) time to copy and store in the result vector.
    // SC : O(N) Recursive Depth
    void solve(string num, vector<string>& result, int idx) {
        if (idx >= num.length()) {
            result.push_back(num);
            return;
        }

        for (int i = idx; i < num.length(); i ++) {
            swap(num[idx], num[i]);
            solve(num, result, idx + 1);
            swap(num[idx], num[i]);
        }
    }

    // TC : O(N! * log(N!))  Sorting a total of N! permutations
    // SC : O(N!)            Storing a total of N! permutations
    string brute(int n, int k) {
        vector<string> result;
        string num;
        for (int i = 1; i <= n; i ++) {
            num += to_string(i);
        }
        solve(num, result, 0);
        sort(begin(result), end(result));
        return result[k - 1];
    }

    long long getFactorial(int n) {
        if (n <= 1) return n;

        return n * getFactorial(n - 1);
    }

    // TC : O(N^2)
    // SC : O(1)
    string optimal(int n, int k) {
        string num = "";
        for (int i = 1; i <= n; i ++) {
            num += to_string(i);
        }

        k = k - 1;
        if (k <= 0) return num;

        string res = "";
        while (num.length() > 0) { // O(N)
            int len  = (num.length() - 1 <= 1) ? 1 : num.length() - 1;
            int fact = getFactorial(len);
            int idx  = k / fact;
            
            res += num[idx];

            k %= fact;
            num.erase(idx, 1);  // O(N)
        }
        return res;
    }
public:
    string getPermutation(int n, int k) {
        // return brute(n, k);

        return optimal(n, k);
    }
};