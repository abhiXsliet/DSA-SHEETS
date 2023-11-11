// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC = O(N * N)
    // SC = O(1)
    long long solve_brute(int arr[], int n) {
        long long maxWater = 0;
        for (int i = 1; i < n; i++) {
            int leftMax = arr[i];
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, arr[j]);
            }
            
            int rightMax = arr[i];
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, arr[j]);
            }
            
            maxWater += max(0, min(leftMax, rightMax) - arr[i]);
        }
        return maxWater;
    }
    
    // TC = O(N)
    // SC = O(N)
    long long solve_better(int arr[], int n) {
        long long maxWater = 0;
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        leftMax[0]      = arr[0];
        rightMax[n - 1] = arr[n - 1];
        
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }
        
        for (int i = 0; i < n; i++) {
            maxWater += max(0, min(leftMax[i], rightMax[i]) - arr[i]);
        }
        
        return maxWater;
    }
    
    // TC = O(N)
    // SC = O(1)
    long long solve_optimal(int arr[], int n) {
        long long maxWater = 0;
        
        int left  = 0;
        int right = n - 1;
        
        int maxLeft  = 0;
        int maxRight = 0;
        
        while(left <= right) {
            if (arr[left] <= arr[right]) {
                if (maxLeft <= arr[left]) {
                    maxLeft = arr[left];
                }
                else {
                    maxWater += maxLeft - arr[left];
                }
                left++;
            }
            else {
                if (maxRight <= arr[right]) {
                    maxRight = arr[right];
                }
                else {
                    maxWater += maxRight - arr[right];
                }
                right--;
            }
        }
        
        return maxWater;
    }
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // return solve_brute(arr, n);
        
        // return solve_better(arr, n);
        
        return solve_optimal(arr, n);
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends