// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(v) where v is the number of vertices
    // SC : O(1)
    bool isPossibleToColor (int node, int color, vector<int>& colored, unordered_map<int, vector<int>>& adj) {
        for (int& nbr : adj[node]) {
            if (colored[nbr] == color) {
                return false;
            }
        }
        return true;
    }
    
    // TC : O(m^v) where m is the number of colors and v is the number of vertices
    // SC : O(m) due to recursion stack 
    bool solve(int node, int v, int m, vector<int>& colored, unordered_map<int, vector<int>>& adj) {
        if (node == v + 1) return true;
        
        for (int color = 1; color <= m; color ++) {
            if (isPossibleToColor(node, color, colored, adj)) {
                colored[node] = color;
                if (solve(node + 1, v, m, colored, adj)) {
                    return true;
                } else {
                    colored[node] = 0;
                }
            } 
        }
        return false;
    }
  public:
    // TC : O(m^v) where m is the number of colors and v is the number of vertices
    // SC : O(v^2) due to the adjacency list representation
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        unordered_map<int, vector<int>> adj;
        for (pair<int, int>& edge : edges) {
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        // keeps track of which node is colored with which color?
        vector<int> colored(v + 1, 0);
        return solve(0, v, m, colored, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}
// } Driver Code Ends