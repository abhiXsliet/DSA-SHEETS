// https://www.geeksforgeeks.org/problems/smallest-factorial-number5929/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
    // TC : O(log5(N))
    int isPossible(int n, int mid) {
        // is it possible to achieve 'n' trailing zeros with mid value
        int cntZero = 0;
        int divisor = 5;
        while (mid >= divisor) {
            cntZero += (mid / divisor);
            divisor *= 5;
        }
        return cntZero >= n;
    }
    public:
    // TC : O(log2(N) * log5(N))
    // SC : O(1)
    int findNum(int n)
    {
        int low = 0, high = 5*n;
        int smallestNo = high;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (isPossible(n, mid)) {
                smallestNo = mid;
                high       = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return smallestNo;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends