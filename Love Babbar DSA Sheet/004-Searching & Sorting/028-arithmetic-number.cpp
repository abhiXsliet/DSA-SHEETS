// https://www.geeksforgeeks.org/problems/arithmetic-number2815/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // TC : O(B)
    int brute(int A, int B, int C) {
        vector<int> v{A, B, C};
        while (v[0] != v[1]) {
            v[0] += v[2];
            if (v[0] == v[1])
                return true;
            else if (v[0] >= v[1]) break;
        }
        return false;
    }
    
    // TC : O(1)
    int optimal(int A, int B, int C) {
        if (C == 0) 
            return A == B;
        else if (C > 0 && B >= A && (B - A) % C == 0)
            return true;
        else if (C < 0 && B <= A && (A - B) % (-C) == 0)
            return true;
        else return false;
    }
public:
    int inSequence(int A, int B, int C){
        // return brute(A, B, C);
        
        return optimal(A, B, C);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends