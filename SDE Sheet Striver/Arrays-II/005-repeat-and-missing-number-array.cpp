// https://www.interviewbit.com/problems/repeat-and-missing-number-array/



#include <bits/stdc++.h>
using namespace std;
#define ll long long

// TC : O(N)
// SC : O(N)
vector<int> approach_1(const vector<int>& arr) {
    int n = arr.size();
    int A = -1, B = -1;
    vector<int> tempArr = arr;  // Create a copy of the input array

    for (int i = 0; i < n; i++) {
        while (tempArr[i] != i + 1) {
            int idx = tempArr[i] - 1;
            if (tempArr[i] == tempArr[idx]) {
                A = tempArr[i];  // Found the repeated number
                break;
            }
            swap(tempArr[i], tempArr[idx]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (tempArr[i] != i + 1) {
            B = i + 1;  // Found the missing number
            break;
        }
    }

    return {A, B};
}

// TC : O(N)
// SC : O(1)
vector<int> approach_2(const vector<int>& arr) {
    int n  = arr.size();
    
    // let x = repeating no. and y = missing no.
    
    // sum of n natural no.s
    ll sn  = (n * (n + 1LL)) / 2;  
    // sum of squares of n natural no.s
    ll s2n = (n * (n + 1LL) * (2*n + 1LL)) / 6; 
    
    // sum of all no. of given no.s of array
    ll s   = 0;
    // sum of squares of given no.s of array
    ll s2  = 0;
    for (int i = 0; i < n; i ++) {
        s  += (ll)arr[i];
        s2 += (ll)arr[i] * (ll)arr[i];
    }
    
    ll diff1 = s  - sn;     // x - y 
    ll diff2 = s2 - s2n;    // x^2 - y^2 : (x + y)(x - y)
    diff2 = diff2 / diff1;   // x + y 
    
    ll x = (diff1 + diff2) / 2;    // missing no.   => 2x = diff1 + diff2
    ll y = diff2 - x;              // repeating no.
    
    return {(int)x, (int)y};
}

// TC : O(N)
// SC : O(1)
vector<int> approach_3(const vector<int>& arr) {
    int n = arr.size();
    
    int xor_all = 0;
    for (int i = 1; i <= n; i ++) {
        xor_all ^= arr[i - 1];
        xor_all ^= i;
    }
    
    int mask = (xor_all) & (-xor_all);
    
    int groupA = 0; // repeated No
    int groupB = 0; // missing No
    for (int i = 1; i <= n; i ++) {
        if (i & mask) {
            groupA ^= i;
        } else {
            groupB ^= i;
        }
        
        if (arr[i - 1] & mask) {
            groupA ^= arr[i - 1];
        } else {
            groupB ^= arr[i - 1];
        }
    }
    
    bool found = 0;
    for (int i = 0; i < n; i ++) {
        if (arr[i] == groupA) { // groupA is repeating no. then
            found = 1;
            break;
        }
    }
    
    if (found) {
        return {groupA, groupB};
    }
    
    return {groupB, groupA};
}

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    // return approach_1(arr);  // place no.s at their indices
    
    // return approach_2(arr);  // math: find 2-eqn : x - y using sum - sumN(sum of n natural no.s) where x = missing no. 
                                //                  : x + y using sum of sq. - sumSqN(sum of sq of n natural no.s)
    
    return approach_3(arr);     // using XOR 
}