// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1



//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC : O(N)
    // SC : O(N)
    int solve_brute(int arr[], int n) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]] ++;
        }
        
        for (auto& it : mpp) {
            if (it.second > floor(n/2)) 
                return it.first;
        }
        return -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(int arr[], int n) {
        int majEle = -1;
        int count  = 0;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                majEle = arr[i];
                count  = 1;
            }
            else if (majEle == arr[i]) {
                count ++;
            }
            else count --;
        }
        // Verify the freq of majority element
        count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == majEle) {
                count ++;
            }
        }
        if (count > floor(n/2)) 
            return majEle;
        return -1;
    }
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // return solve_brute(a, size);
        
        return solve_optimal(a, size);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends