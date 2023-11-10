// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
private:
    // TC = O(N * N)
    // SC = O(1)
    vector<int> solve_1(int N) {
        vector<int> arr(10000, 0);
        arr[0] = 1;  // put 1 at the first index
        int size  = 1;  // size of vector till element is available
        
        for (int el = 2; el <= N; el++) {
            
            int carry = 0;
            for (int j = 0; j < size; j++) {
                
                int value = arr[j] * el + carry;
                
                arr[j] = value % 10;
                carry     = value / 10;
            }
            // e.g., if carry = 13
            while (carry != 0) {
                arr[size++] = carry % 10;
                carry /= 10;
            }
        }
        
        vector<int> result;
        for (int i = size - 1; i >= 0; i--) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
    
    void multiply(vector<int>& result, int num) {
        int carry = 0;
        
        for (int j = 0; j < result.size(); j++) {
            int val = result[j] * num + carry;
            
            result[j] = val % 10;
            carry     = val / 10;
        }
        
        while(carry != 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    // TC = O(N * N)
    // SC = O(1)
    vector<int> solve_2(int N) {
        vector<int> result;
        result.push_back(1);
        
        for (int i = 2; i <= N; i++) {
            multiply(result, i);
        }
        reverse(begin(result), end(result));
        return result;
    }
public:
    vector<int> factorial(int N){
        // return solve_1(N);
        
        return solve_2(N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends