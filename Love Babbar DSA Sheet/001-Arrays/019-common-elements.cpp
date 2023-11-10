// https://practice.geeksforgeeks.org/problems/common-elements1132/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:  
        // TC = O(n1 + n2 + n3)  
        // SC = O(n1 + n2 + n3)  
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int n = n1 + n2 + n3;
            vector<int> result;
            
            int p1, p2, p3;
            p1 = p2 = p3 = 0;
            
            int prev1, prev2, prev3;
            prev1 = prev2 = prev3 = INT_MIN;
            
            while (p1 < n1 && p2 < n2 && p3 < n3) {
                // if arr1 ele == prev1 then skip
                while (A[p1] == prev1 && p1 < n1) {
                    p1++;
                }
                // if arr2 ele == prev2 then skip
                while (B[p2] == prev2 && p2 < n2) {
                    p2++;
                }
                // if arr3 ele == prev3 then skip
                while (C[p3] == prev3 && p3 < n3) {
                    p3++;
                }
                
                // if arr1 ele == arr2 ele == arr3 ele 
                // then store and update prev1, prev2, prev2 and move ahead
                if (A[p1] == B[p2] && B[p2] == C[p3]) {
                    // store in result
                    result.push_back(A[p1]);
                    
                    prev1 = A[p1];
                    prev2 = B[p2];
                    prev3 = C[p3];
                    
                    p1++, p2++, p3++;
                }
                // arr1 ele is less than arr2 ele then move and update prev1
                else if (A[p1] < B[p2]) {
                    prev1 = A[p1];
                    p1++;
                }
                // arr2 ele is less than arr3 ele then move and update prev2
                else if (B[p2] < C[p3]) {
                    prev2 = B[p2];
                    p2++;
                }
                // arr3 ele is less then move and update prev3
                else {
                    prev3 = C[p3];
                    p3++;
                }
            }
            
            return result;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends