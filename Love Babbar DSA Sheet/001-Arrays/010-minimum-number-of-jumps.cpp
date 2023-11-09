// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  private:
    // TC = O(N * N) -> TLE
    int solve_tabulation(int arr[], int n) {
        
        vector<int> minJumps (n, 1e9);
        vector<int> jumpFrom (n, -1);
        
        minJumps[0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] + j >= i) {
                    minJumps[i] = min(minJumps[i], minJumps[j] + 1);
                    jumpFrom[i] = j;
                }
            }
        }
        
        return minJumps[n - 1] == 1e9 ? -1 : minJumps[n - 1];
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_greedy(int arr[], int n) {
        
        if (n == 1) return 0;
        if (arr[0] == 0) return -1;
        
        int steps    = arr[0];
        int maxReach = arr[0];
        
        int minJumps = 1;
        
        for (int i = 1; i < n; i++) {
            if (i == n - 1) 
                return minJumps;
                
            steps--;
            
            maxReach = max(maxReach, arr[i] + i);
            
            if (steps == 0) {
                minJumps++;
                if (i >= maxReach)
                    return -1;
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
  public:
    int minJumps(int arr[], int n){
        // return solve_tabulation(arr, n);
        
        return solve_greedy(arr, n);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends