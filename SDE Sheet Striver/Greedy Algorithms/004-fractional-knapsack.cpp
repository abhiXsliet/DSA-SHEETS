// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};
// } Driver Code Ends

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        auto cmp = [](Item i1, Item i2) {
            return (double)i1.value/i1.weight >= (double)i2.value/i2.weight;  
        };
        sort(arr, arr + n, cmp);
        
        double maxVal = 0.0;
        for (int i = 0; i < n; i ++) {
            if (w >= arr[i].weight) {
                maxVal += arr[i].value;
                w      -= arr[i].weight;
            } else {
                maxVal += ((double)arr[i].value / (double)arr[i].weight) * w;
                w = 0;
                break;
            }
        }
        return maxVal;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends