// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends

// TC = O(N)
// SC = O(1)
void solve_brute(int arr[], int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

// TC = O(N)
// SC = O(1)
void solve_optimal(int arr[], int n) {
    for (int i = n - 1; i > 0; i--)
        swap(arr[i], arr[i - 1]);
}

//User function Template for C++
void rotate(int arr[], int n)
{
    // solve_brute(arr, n);
    
    solve_optimal(arr, n);
}