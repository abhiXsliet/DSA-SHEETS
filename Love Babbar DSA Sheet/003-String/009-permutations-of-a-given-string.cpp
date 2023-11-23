// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        // TC = O(n! * n)
        // SC = O(n! * n)
        void solve(string& s, int idx, int n, set<string>& st) {
            if (idx >= n) {
                st.insert(s);
                return;
            }
            
            for (int i = idx; i < n; i++) {
                swap(s[i], s[idx]);
                solve(s, idx+1, n, st);
                swap(s[i], s[idx]);
            }
        }
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> result;
		    set<string> st;
		    solve(S, 0, S.length(), st);
		    for (auto& s : st) {
		        result.push_back(s);
		    }
		    return result;
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends