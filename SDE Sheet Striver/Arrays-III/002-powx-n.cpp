// https://leetcode.com/problems/powx-n/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // TC : O(log(N))
    // SC : O(1)
    double approach_1(double x, int n) {
        double ans = 1;
        ll power   = n;
        
        if (n < 0) power *= (-1);
        
        while (power) {
            if (power % 2) {
                ans *= x;
                power --;
            } else {
                x *= x;
                power >>= 1;
            }
        }

        if (n < 0)
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }

    // TC : O(log(N))
    // SC : O(1) but recursive depth : O(log(N))
    double rec(double x, ll power) {
        if (x == 0)     return 0;
        if (power == 0) return 1;

        double ans = 1.0;
        double val = 1.0;

        if (power % 2) {
            ans *= x;
            val  = approach_2(x, power - 1);
        } else {
            val = approach_2(x * x, power / 2);
        }

        ans *= val;
        return ans;
    }

    // TC : O(log(N))
    // SC : O(1)
    double approach_2(double x, int n) {
        ll power = n;
        if (n < 0) power *= (-1);

        double ans = rec(x, power);

        if (n < 0) 
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
public:
    double myPow(double x, int n) {
        // return approach_1(x, n);  // ITERATIVE 

        return approach_2(x, n);  // RECURSIVE   
    }
};