// https://www.geeksforgeeks.org/problems/middle-of-three2926/1



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC : O(1)
    int approach_1(int A, int  B, int C) {
        if      ( (A > B && A < C) || (A < B && A > C) )return A;
        else if ( (B > C && B < A) || (B > A && B < C)) return B;
        else return C;
    }
    // TC : O(1)
    int approach_2(int A, int  B, int C) {
        return (A + B + C) - max({A, B, C}) - min({A, B, C});
    }
  public:
    int middle(int A, int B, int C){
        // return approach_1(A, B, C);
        
        return approach_2(A, B, C);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends