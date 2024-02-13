// https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1



//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
private:
    typedef long long int ll;
    
    // TC : O(N^3)
    // SC : O(1)
    ll solve_brute(vector<ll>& arr, int n) {
        int subarray_cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ll sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum == 0) subarray_cnt ++;
            }
        }
        return subarray_cnt;
    }

    // TC : O(N^2)
    // SC : O(1)
    ll solve_better(vector<ll>& arr, int n) {
        int subarray_cnt = 0;
        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) subarray_cnt ++;
            }
        }
        return subarray_cnt;
    }
    
    // TC : O(N)
    // SC : O(N)
    ll solve_optimal(vector<ll>& arr, int n) {
        int subarray_cnt = 0;
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (mpp.find(sum) != mpp.end()) {
                subarray_cnt += mpp[sum];
            }
            mpp[sum] ++;
        }
        
        return subarray_cnt;
    }
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        // return solve_brute(arr, n);
        
        // return solve_better(arr, n);
        
        return solve_optimal(arr, n);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends