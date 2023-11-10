// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
  private:
    long long solve_brute(long long arr[], int n) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    
    long long merge(long long arr[], int low, int mid, int high) {
        long long cnt = 0; // to count the no. of inversions
        vector<long long> temp;
        
        int left  = low;
        int right = mid + 1;
        
        while(left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            }
            else {
                temp.push_back(arr[right++]);
                cnt += mid - left + 1;  // inversion will be counted iff right element is smaller than left
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left++]);
        }
        
        while(right <= high) {
            temp.push_back(arr[right++]);
        }
        
        // sorted array 
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        return cnt;
    }
    
    long long mergeSort(long long arr[], int low, int high) {
        long long cnt = 0;
        
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid+1, high);
        
        cnt += merge(arr, low, mid, high);
        
        return cnt;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    long long solve_optimal(long long arr[], int n) {
        return mergeSort(arr, 0, n-1);
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // return solve_brute(arr, N);
        
        return solve_optimal(arr, N);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends