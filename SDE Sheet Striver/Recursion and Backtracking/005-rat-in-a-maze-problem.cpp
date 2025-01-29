// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    vector<vector<int>> directions {{-1, 0, 1}, {1, 0, 2}, {0, -1, 3}, {0, 1, 4}};
    
    bool isPossibleToMove(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;    
    }
    
    // TC : O(3^(N*N)) The rat can only move down, left, or right, not up (since upward is already visited)
    // SC : O(N*N) Recursive Depth
    void solve(int i, int j, int n, vector<string>& result, string &path, vector<vector<int>>& mat) {
        if (!isPossibleToMove(i, j, n) || !mat[i][j])
            return;
            
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }
        
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            char ch = (dir[2] == 1) ? 'U' : (dir[2] == 2) ? 'D' : (dir[2] == 3) ? 'L' : 'R';
            
            mat[i][j] = 0;  // moved to i, j so add it to the path also mark it 0 
            path.push_back(ch);

            solve(i_, j_, n, result, path, mat);
            
            path.pop_back();
            mat[i][j] = 1;  // backtrack 
        }
    }
  public:
    // TC : O(3^(N^2))
    // SC : O(N) extra space used by path
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> result;
        string path;
        solve(0, 0, n, result, path, mat);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends