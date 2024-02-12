// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1



//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

// TC : O(N^2) Where N = size of array
// SC : O(1)
bool solve_brute(int nums[], int size, int diff) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(nums[j] - nums[i]) == diff) {
                return 1;
            }
        }
    }
    return 0;
}

// TC : O(log(N)) Where N = size of array
bool getNum(int nums[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return 1;
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return 0;
}

// TC : O(N * log(N))
// SC : O(1)
bool solve_optimal(int nums[], int size, int diff) {
    sort(nums, nums + size);
    for (int i = 0; i < size; i++) {
        int tar = nums[i] + diff;
        if (getNum(nums, i + 1, size, tar)) {
            return 1;
        }
    }
    return 0;
}

bool findPair(int arr[], int size, int n){
    // return solve_brute(arr, size, n);
    
    return solve_optimal(arr, size, n);
}