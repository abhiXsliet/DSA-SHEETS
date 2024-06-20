// https://www.spoj.com/problems/EKO/

// Same Problem : https://www.geeksforgeeks.org/problems/cut-woods/0


//{ Driver Code Starts
/* Driver program to test above function */
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function Template for C++
class Solution{
    private:
    bool isOptimalCut(vector<int>& arr, int M, int mid) {
        // is it possible to cut all trees above 'mid' height
        // and could be achieved the required 'M' Height ??
        int n = arr.size();
        long sumHeight = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] > mid) {
                sumHeight += arr[i] - mid;
            }
        }
        return sumHeight >= M;
    }
    public:
    // TC : O(N*log(max_element)) Where N = Size of array of heights
    // & max_element is the maximum value of element in arr of heights
    // SC : O(1)
    int maxHeight(vector<int>&A, int M){
        int low  = 0;
        int high = *max_element(begin(A), end(A));
        int maxHeight = low;
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (isOptimalCut(A, M, mid)) {
                maxHeight = mid;    // Try to Maximize woods cut to avoid more 
                low  = mid + 1;     // than necessary cutting of woods
            } else {
                high = mid - 1;
            }
        }
        return maxHeight;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0; i < n; i++){
	       cin >> A[i];
	    }
	    int M;
	    cin >> M;
	    Solution ob;
	    int ans = ob.maxHeight(A, M);
	    cout << ans <<endl;
	}
	return 0;
}
// } Driver Code Ends