// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends

class Solution{
    private:
    typedef long long ll;
    
    // TC : O(N + M)
    // SC : O(N + M)
    void solve_brute(ll arr1[], ll arr2[], int n, int m) {
        ll ans[n + m];
        
        int i = 0, j = 0, k = 0;
        
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) 
                ans[k++] = arr1[i++];
            else 
                ans[k++] = arr2[j++];
        }
        
        while (i < n) {
            ans[k++] = arr1[i++];
        }
        
        while (j < m) {
            ans[k++] = arr2[j++];
        }
        
        for (int i = 0; i < (n + m); i++) {
            if (i < n) 
                arr1[i] = ans[i];
            else 
                arr2[i - n] = ans[i];
        }
    }
    
    // TC : O(min(N, M)) + O(N * log(N)) + O(M * log(M))
    // SC : O(1)
    void solve_better(ll arr1[], ll arr2[], int n, int m) {
        int i = n - 1,  j = 0;
        
        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) 
                swap(arr1[i--], arr2[j++]);
            else break;
        }
        
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
    
    void swapIfGreater(ll arr1[], ll arr2[], int i, int j) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
    }
    
    // TC : O(log(n) * (n + m))
    // SC : O(1)
    void solve_optimal(ll arr1[], ll arr2[], int n, int m) {
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        
        while (gap > 0) {
            int i = 0;
            int j = i + gap;
            while (j < len) {
                // comparing arr1 & arr2
                if (i < n && j >= n) {
                    swapIfGreater(arr1, arr2, i, j - n);
                }
                // comparing arr2 & arr2
                else if (i >= n) {
                    swapIfGreater(arr2, arr2, i - n, j - n); // swap in arr2 only
                }
                // comparing arr1 & arr1
                else {
                    swapIfGreater(arr1, arr1, i, j);    // swap in arr1 only
                }
                i ++;
                j ++;
            }
            
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
    public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        // solve_brute(arr1, arr2, n, m);
        
        // solve_better(arr1, arr2, n, m);
        
        solve_optimal(arr1, arr2, n, m);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
// } Driver Code Ends