// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  private:
    // TC = O(N * N * N) -> TLE
    // SC = O(1)
    int solve_brute(int arr[], int n, int tar) {
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                    if (sum > tar) {
                        minLen = min(minLen, k - i + 1);
                    }
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // TC = O(N * N) -> TLE
    // SC = O(1)
    int solve_better(int arr[], int n, int tar) {
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                
                if (sum > tar) {
                    minLen = min(minLen, j - i + 1);
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // TC = O(N)
    // SC = O(1)
    // Sliding Window Approach
    int solve_optimal(int arr[], int n, int tar) {
        int minLen = INT_MAX;
        int sum = 0;
        int start = 0;
        
        for (int end = 0; end < n; end++) {
            sum += arr[end];
            while (sum > tar) {
                minLen = min(minLen, end - start + 1);
                sum -= arr[start];
                start++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
  public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        // return solve_brute(arr, n, x);
        
        // return solve_better(arr, n, x);
        
        return solve_optimal(arr, n, x);
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends