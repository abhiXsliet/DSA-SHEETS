// https://www.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1



//{ Driver Code Starts
// C++ program to search an element in an array
// where difference between all elements is 1
#include<bits/stdc++.h>
using namespace std;

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k);


// Driver program to test above function
int main()
{
	int t,n,k,x;
	cin>>t;
	while(t--)
    {

        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>x;
        cout<<search(arr, n, x, k)<<endl;

    }
return 0;
}
// } Driver Code Ends

// TC : O(N)
int solve_brute(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// TC : O(N)
int solve_optimal(int arr[], int n, int x, int k) {
    int i = 0;
    while (i < n) {
        if (arr[i] == x) 
            return i;
        
        // diff = target - currEle, 
        // a/c to array property => x must be atleast diff/k
        i = i + max(1, abs(x - arr[i]) / k);
    }
    return -1;
}

// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // return solve_brute(arr, n, x);	
    
    return solve_optimal(arr, n, x, k);
}    	