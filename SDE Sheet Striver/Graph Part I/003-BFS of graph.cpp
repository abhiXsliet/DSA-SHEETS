// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    void bfs(vector<int>& result, vector<vector<int>> &adj, vector<int> &visited, int src) {
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while (!q.empty()) {
            int fNode = q.front();
            q.pop();
            
            result.push_back(fNode);
            
            for (int nbr : adj[fNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
  public:
    // TC : O(N)
    // SC : O(N)
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> result;
        vector<int> visited(n, 0);
        bfs(result, adj, visited, 0);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends