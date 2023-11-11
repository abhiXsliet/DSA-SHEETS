// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1


//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
private:
    // TC = O(N * N) -> TLE
    // SC = O(1)
    int solve_brute(int arr[], int n, int k) {
        // Count all elements less than or equal to k
        int good = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] <= k) good++;
            
        // Initialize minSwaps as maximum integer value
        int minSwaps = INT_MAX;
            
        // Traverse for every sub-array
        for (int i = 0; i <= n - good; i++) {
            int cnt = 0;
            // Swap those elements whose value is greater than k
            for (int j = i; j < good + i; j++) {
                if (arr[j] > k) cnt++;
            }
            // Update minSwaps
            minSwaps = min(minSwaps, cnt);
        }
        return minSwaps == INT_MAX ? 0 : minSwaps;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Two Pointer Approach
    int solve_optimal_1(int arr[], int n, int k) {
        int good = 0;
        
        for (int i = 0; i < n; i++)
            if (arr[i] <= k) good++;
            
        int bad = 0;
        for (int i = 0; i < good; i++) 
            if (arr[i] > k) bad++;
        
        // assign the total bad count in ans
        int ans = bad;
        
        
        int left  = 0;
        int right = good;
        // process every window of size good
        while (right < n) {
            // decrement the count of prev window
            if (arr[left]  > k) bad--;
            
            // increment the count of curr window
            if (arr[right] > k) bad++;
            
            // Update ans if count
            // is less in current window
            ans = min(ans, bad);
            
            right++;
            left++;
        }
        
        
        // for (int left = 0, right = good; right < n; right++, left++) {
        //     if (arr[left]  > k) bad--;
        //     if (arr[right] > k) bad++;
        //     ans = min(ans, bad);
        // }
        
        return ans;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Sliding Window Appraoch
    int solve_optimal_2(int arr[], int n, int k) {
        int good = 0;
        
        for (int i = 0; i < n; i++)
            if (arr[i] <= k) good++;
            
        int bad = 0;
        for (int i = 0; i < good; i++) 
            if (arr[i] > k) bad++;
        
        
        int swap = bad;
        int ans_swap = INT_MAX;
        ans_swap = min(ans_swap, swap);
        
        for (int i = good; i < n; i++) {
            if (arr[i - good] <= k && arr[i] > k) 
                swap++;
            else if (arr[i - good] > k && arr[i] <= k)
                swap--;
            
            ans_swap = min(ans_swap, swap);
        }
        
        return ans_swap;
    }
public:
    int minSwap(int arr[], int n, int k) {
        // return solve_brute(arr, n, k);
        
        // return solve_optimal_1(arr, n, k);
        
        return solve_optimal_2(arr, n, k);
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends