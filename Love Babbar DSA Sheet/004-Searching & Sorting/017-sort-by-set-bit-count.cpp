// https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
    // TC : O(32) * n-times get called -> Giving TLE
    
    // __builtin_popcount function is likely implemented using hardware instructions 
    // and is much faster than the manual bit counting
    int getSetBits(int num) {
        int bits = 0;
        for (int i = 31; i >= 0; i--) {
            if ((1 << i) & num) {
                bits++;
            }
        }
        return bits;
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    void solve_approach_1(int arr[], int n) {
        vector<pair<int, int>> store(n);
        
        for (int i = 0; i < n; i++) {
            int setBits = __builtin_popcount(arr[i]);
            store[i] = {arr[i], setBits};
        }
        
        // Stable sorting maintains the order of the two equal elements
        // However, it does not guarantee the order of elements that are not equal.
        stable_sort(begin(store), end(store), [&](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second)
                return false;
            return a.second > b.second;
        });
        
        for (int i = 0; i < n; i++) {
            arr[i] = store[i].first;
        }
        
        return;
    }
    
    // TC : O(N * log(N))
    // SC : O(1)
    void solve_approach_2(int arr[], int n) {
        auto cmp = [&] (int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            if (countA == countB) 
                return false;
            return countA > countB;
        };
        
        stable_sort(arr, arr + n, cmp);
        return;
    }
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // solve_approach_1(arr, n);
        
        solve_approach_2(arr, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends