// https://practice.geeksforgeeks.org/problems/next-permutation5226/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // TC = O(N)
    // SC = O(1)
    vector<int> nextPermutation(int N, vector<int> arr){
        int n = arr.size();
        
        int prev_idx = -1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i+1]) {
                prev_idx = i;
                break;
            }
        }
        
        
        if (prev_idx == -1) {
            reverse(begin(arr), end(arr));
            return arr;
        }
        else {
            int curr_idx = -1;
    
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] > arr[prev_idx]) {
                    curr_idx = i;
                    break;
                }
            }
            
            swap(arr[prev_idx], arr[curr_idx]);
        
            reverse(arr.begin() + prev_idx + 1, arr.end());
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends