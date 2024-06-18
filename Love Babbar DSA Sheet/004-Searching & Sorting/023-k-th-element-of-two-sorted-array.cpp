// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    private:
    // TC : O(N + M)
    // SC : O(1)
    int approach_1(int arr1[], int arr2[], int n, int m, int k) {
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m) {
            cnt += 1;
            if (arr1[i] <= arr2[j]) {
                if (cnt == k) return arr1[i];
                i ++;
            }
            else {
                if (cnt == k) return arr2[j];
                j ++;
            }
        }
        
        while (i < n) {
            cnt += 1;
            if (k == cnt) return arr1[i];
            i ++;
        }
        while (j < m) {
            cnt += 1;
            if (k == cnt) return arr2[j];
            j ++;
        }
        return -1;
    }
    
    // TC : O(min(log(N), log(M)))
    // SC : O(1)
    int approach_2(int arr1[], int arr2[], int n, int m, int k) {
        if (n > m) {
            return approach_2(arr2, arr1, m, n, k);
        }
        // catch
        int low = max(0, k - m), high = min(n, k);
       
        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low  = cut1 + 1;
            }
        }
        return -1;
    }
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        // return approach_1(arr1, arr2, n, m, k);
        
        return approach_2(arr1, arr2, n, m, k);     // OPTIMAL Soln
    }
};
//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends