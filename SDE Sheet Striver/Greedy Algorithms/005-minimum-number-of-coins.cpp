// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int sum) {
        vector<int> coins { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = coins.size();
        
        vector<int> result;
        for (int i = n - 1; i >= 0; i --) {
            while (coins[i] <= sum) {
                result.push_back(coins[i]);
                sum -= coins[i];
                if (sum == 0) break;
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends