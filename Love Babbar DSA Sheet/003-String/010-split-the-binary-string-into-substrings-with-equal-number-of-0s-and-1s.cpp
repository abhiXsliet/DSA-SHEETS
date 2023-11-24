// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/



//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    int solve_approach_1(string& s, int n) {
        int ans = 0;
        stack<int> stk;
        int i = 0;
        stk.push(s[i++]);
        
        while (i < n) {
            while (i < n && !stk.empty() && s[i] != stk.top()) {
                stk.pop();
                i++;
            }
            
            if (stk.empty()) ans++;
            
            while (i < n && ( stk.empty() || s[i] == stk.top()) ) {
                stk.push(s[i++]);
            }
        }
        
        return stk.empty() ? ans : -1;
    }
    
    // TC = O(N)
    // SC = O(1)
    int solve_approach_2(string& s, int n) {
        int ans     = 0;
        int cntZero = 0;
        int cntOne  = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cntZero++;
            if (s[i] == '1') cntOne++;
            if (cntZero == cntOne) ans++;
        }
        if (cntZero != cntOne)
            return -1;
        return ans;
    }
public:
    int maxSubStr(string str){
        // return solve_approach_1(str, str.length());
        
        return solve_approach_2(str, str.length());
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends