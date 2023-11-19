// https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1



//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

// TC = O(N * N * log(K))
// SC = O(K)
int solve_brute(int mat[MAX][MAX], int n, int k) {
    // push all element in a maxheap
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(mat[i][j]);
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    return pq.top();
}

// TC = O(log(N))
int upperBound(int mat[], int n, int val) {
    int low  = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (mat[mid] > val) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

// TC = O(N * log(N))
int range_counter(int mat[MAX][MAX], int n, int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upperBound(mat[i], n, mid);
    }
    return cnt;
}

// TC = O(log(max - min value) * (N * log(N))
// SC = O(1)
// Binary Search On Range
int solve_optimal(int mat[MAX][MAX], int n, int k) {
    int low  = mat[0][0];
    int high = mat[n - 1][n - 1];
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int mid_range_cnt = range_counter(mat, n, mid);
        
        if (mid_range_cnt < k) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return low;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // return solve_brute(mat, n, k);
    
    return solve_optimal(mat, n, k);
}
