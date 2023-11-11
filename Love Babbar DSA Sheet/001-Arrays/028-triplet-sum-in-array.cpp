// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC = O(N * N * N)
    // SC = O(1)
    bool solve_brute(int arr[], int n, int tar) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (arr[i] + arr[j] + arr[k] == tar) 
                        return true;
                }
            }
        }
        return false;
    }

    // TC = O(N * N)
    // SC = O(N)    
    bool solve_better(int arr[], int n, int tar) {
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i + 1; j < n; j++) {
                int third = tar - (arr[i] + arr[j]);
                
                if (st.find(third) != st.end()) 
                    return true;
                
                st.insert(arr[j]);
            }
        }
        return false;
    }
    
    // TC = O(N * N)
    // SC = O(1) 
    bool solve_optimal(int arr[], int n, int tar) {
        sort(arr, arr + n);
        
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] == tar) 
                    return true;
                else if (arr[i] + arr[j] + arr[k] > tar) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return false;
    }
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // return solve_brute(A, n, X);
        
        // return solve_better(A, n, X);
        
        return solve_optimal(A, n, X);
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends