// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    // TC = O(n + m)
    // SC = O(n + m)
    int solve_brute(int a[], int n, int b[], int m) {
        
        // Insertion : O(log n), where "n" is the number of elements in the set.
        // Deletion  : O(log n)
        // Search    : O(log n)
        
        set<int> st; 
        
        for (int i = 0; i < n; i++)
            st.insert(a[i]);
            
        for (int j = 0; j < m; j++)
            st.insert(b[j]);
            
        return st.size();
    }
    
    // TC = O(n + m)
    // SC = O(n + m) 
    int solve_optimal(int a[], int n, int b[], int m) {
        
        // unordered_set is more efficient than set
        // Insertion : O(1), O(n) in the worst case, where "n" is the number of elements in the set.
        // Deletion  : O(1), O(n) in the worst case
        // Search    : O(1), O(n) in the worst case
        
        unordered_set<int> st;      
        
        for (int i = 0; i < n; i++)
            st.insert(a[i]);
            
        for (int j = 0; j < m; j++)
            st.insert(b[j]);
            
        return st.size();
    }
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        // return solve_brute(a, n, b, m);
        
        return solve_optimal(a, n, b, m);
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends