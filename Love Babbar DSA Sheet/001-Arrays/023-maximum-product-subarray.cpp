// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    // TC = O(N * N * N)
    // SC = O(1)
    long long solve_brute(vector<int>& arr, int n) {
        long long maxProd = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long prod = 1;
                for (int k = i; k <= j; k++) {
                    prod *= arr[k];
                }
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
    
    // TC = O(N * N)
    // SC = O(1)
    long long solve_better(vector<int>& arr, int n) {
        long long maxProd = INT_MIN;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                prod   *= arr[j];
                maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Intution -> odd/even no. of -ves, zero divides the array into segments
    long long solve_optimal_1(vector<int>& arr, int n) {
        long long maxProd = INT_MIN;
        long long prefix = 1;
        long long suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            prefix *= arr[i];
            suffix *= arr[n - i - 1];
            
            maxProd = max(maxProd, max(prefix, suffix));
        }
        return maxProd;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Intution -> Kadanes modification
    long long solve_optimal_2(vector<int>& arr, int n) {
        long long maxProd = arr[0];
        long long prod1   = arr[0];
        long long prod2   = arr[0];
        for (int i = 1; i < n; i++) {
            long long temp = max({(long long)arr[i], (long long)prod1*arr[i], (long long)prod2*arr[i]});
            prod2 = min({(long long)arr[i], (long long)prod1*arr[i], (long long)prod2*arr[i]});
            prod1 = temp;
            
            maxProd = max(maxProd, prod1);
        }
        return maxProd;
    }
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	   // return solve_brute(arr, n);
	   
	   //return solve_better(arr, n);
	   
	   //return solve_optimal_1(arr, n);
	   
	   return solve_optimal_2(arr, n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends