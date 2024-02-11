// https://www.geeksforgeeks.org/problems/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/1




//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    private:
    // TC : O(M^N) Where M = Average No. Of Words in each list
    // Code generates all possible combinations of words from the lists, and there are (M^N) such combinations
    // SC : O(N) Where N = No. of list (maximum depth of the recursive call stack)
    void solve(vector<vector<string>>& list, vector<string>temp, 
               vector<vector<string>>& result, int m = 0) {
        if (m == list.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < list[m].size(); i++) {
            temp.push_back(list[m][i]);
            solve(list, temp, result, m + 1);
            temp.pop_back();
        }
    }
    public:
    vector<vector<string>> sentences(vector<vector<string>>&list){
        vector<vector<string>> result;
        vector<string> temp;
        solve(list, temp, result);
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends