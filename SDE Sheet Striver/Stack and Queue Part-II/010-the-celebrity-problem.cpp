// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N^2)
    // SC : O(N^2)
    int brute_1(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 1) return 0;
        unordered_map<int, unordered_set<int>> mpp;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j && mat[i][j]) {
                    mpp[j].insert(i);
                }
            }
        }
        int celeb = -1;
        for (auto &it : mpp) {
            if (it.second.size() == n - 1) {
                celeb = it.first;
            }
        }
        for (auto& it : mpp) {
            if (it.second.count(celeb)) {
                return -1;
            }
        }
        return celeb;
    }

    // TC : O(N^2)
    // SC : O(1)
    int brute_2(vector<vector<int>> &mat) {
        int n = mat.size();
        for (int i = 0; i < n; i ++) {
            bool isCeleb = true;
            for (int j = 0; j < n; j ++) {
                if (i == j) continue;
                if (mat[i][j]) {    //  celeb shouldn't knows anyone : but here celeb 'i' knows 'j' which violates our condn.
                    isCeleb = false;
                    break;
                }
            }
            if (isCeleb) {  // everyOne should know celeb 'i'
                for (int i_ = 0; i_ < n; i_ ++) {
                    if (!mat[i_][i]) {
                        isCeleb = false;
                        break;
                    }
                }
            }
            if (isCeleb) return i;
        }
        return -1;
    }
    
/*
    - persons : 0, 1, 2, ..., n
    - check two persons only (A, B) : if A knows B, A can't be celebrity => put B in ds
                                    : if B knows A, B can't be celebrity => put A in ds
*/    
    // TC : O(N)
    // SC : O(N)
    int better(vector<vector<int>> &mat) {
        int n = mat.size();
        
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            q.push(i);
        }
        
        auto isKnows = [&](int A, int B) {
            return mat[A][B];   // A knows B : mat[A][B] == 1
        };
            
        int celeb = -1;
        while (q.size() >= 1) {
            if (q.size() == 1) {
                celeb = q.front();
                q.pop();
                break;
            }
            
            int A = q.front(); q.pop();
            int B = q.front(); q.pop();
            
            if (isKnows(A, B)) {    // A knows B : A can't be celeb thus push B in queue
                q.push(B);
            } else {
                q.push(A);
            }
        }
        
        // validate celeb
        for (int k = 0; k < n; k ++) {
            if (k != celeb && (mat[celeb][k] || !mat[k][celeb])) {
                return -1;
            }
        }
        
        return celeb;
    }
    
/*
    // --------------------------------- Two Pointer Approach ----------------------------------------
    1. Set two pointers: i = 0 and j = n - 1
    2. Eliminate non-celebrities:
       - If mat[i][j] == 1, increment i (i can't be the celebrity, since celebrity knows no one)
       - If mat[i][j] == 0, decrement j (j can't be the celebrity, since celebrity is known by everyone)
    3. Once the loop ends, i points to a potential celebrity
    4. Confirm i is the celebrity by validating its row and column
*/
    // TC : O(N)
    // SC : O(1)
    int optimal(vector<vector<int>> &mat) {
        int n = mat.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (mat[i][j]) {    // i knows j : celebrity knows no one, so increase i
                i ++;
            } else {    // i doesn't know j : decrease j, since celebrity is known by everyone
                j --;
            }
        }
        
        int celeb = i;
        
        // validate 'i' to be a celebrity in its row and col
        for (int k = 0; k < n; k ++) {
            if (k != i && (mat[celeb][k] || !mat[k][celeb])) {   
                return -1;
            }
        }
        return celeb;
    }
  public:
    int celebrity(vector<vector<int>> &mat) {
        // return brute_1(mat);   
        // return brute_2(mat);
        // return better(mat);  // Using Queue
        return optimal(mat); // Using Two Pointer : O(N)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends