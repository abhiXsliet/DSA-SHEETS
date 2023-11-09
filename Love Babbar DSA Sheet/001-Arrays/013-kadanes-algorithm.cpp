// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:  
    // TC = O(N * N * N)
    // SC = O(1)
    long long solve_brute(int arr[], int n) {
        long long maxSum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                long long sum    = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
    
    // TC = O(N * N)
    // SC = O(1)
    long long solve_better(int arr[], int n) {
        long long maxSum = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            
            long long sum    = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                maxSum = max(maxSum, sum);
            }
            
        }
        
        return maxSum;
    }
    
    // TC = O(N)
    // SC = O(1)
    long long solve_optimal_kadanes(int arr[], int n) {
        long long maxSum = INT_MIN;
        long long sum    = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        
        return maxSum;
    }
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        // return solve_brute(arr, n);
        
        // return solve_better(arr, n);
        
        return solve_optimal_kadanes(arr, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends