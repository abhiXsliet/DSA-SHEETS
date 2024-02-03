// https://www.geeksforgeeks.org/problems/find-the-string-in-grid0111/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    vector<vector<int>> dir {
                                {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, 
                                {1, 1}, {1, 0}, {1, -1}, {0, -1},
    
                            };
    // TC (At Worst): O(|word|) where |word| is the length of the word
    // SC (AT Worst): O(|word|)  -> Depth of recursion
    bool dfs(vector<vector<char>>grid, string word, int new_i, int new_j, int i, int j, int idx) {
        if (idx >= word.length()) return true;
        
        if ( new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[0].size() ) 
            return false;
            
        if (grid[new_i][new_j] == word[idx]) {
            return dfs(grid, word, new_i + i, new_j + j, i, j, idx + 1);
        }
        else return false;
    }
public:
    // TC : O(N * M * |word|) ~= O(N*M*K)
    // SC : O(1) no extra space used 
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        vector<vector<int>> result;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j] == word[0]) {
                    
                    // explore 8-directions and find whole word
                    for (auto& d : dir) {        
                        int new_i = i + d[0];
                        int new_j = j + d[1];
                        
                        if (dfs(grid, word, new_i, new_j, d[0], d[1], 1)) {
                            result.push_back({i, j});
                            break;
                        }
                        
                    }
                }
            }
        }
        return result;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends