// https://practice.geeksforgeeks.org/problems/max-rectangle/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
    // TC = O(N)
    // SC = O(N)
    // This function is calculating the indexes of prev smaller element
    vector<int> getPrevSmallerHeight(vector<int>& height, int n) {
        
        stack<int> stk;
        stk.push(-1);
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            
            while(stk.top() != -1 && height[stk.top()] >= height[i]) {
                stk.pop();
            }
            
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(N)
    // This function is calculating the indexes of next smaller element
    vector<int> getNextSmallerHeight(vector<int>& height, int n) {
        
        stack<int> stk;
        stk.push(-1);
        
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            
            while((stk.top() != -1) && (height[stk.top()] >= height[i])) {
                stk.pop();
            }
            
            // in case you push_back to the ans 
            // then you have to reverse it in the end
            // since indexes will get pushed into ans in reverse
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(N)
    int getLargestArea(vector<int>& height) {
        int n = height.size();
        
        vector<int> prevSmaller(n); 
        prevSmaller= getPrevSmallerHeight(height, n);
        
        vector<int> nextSmaller(n);
        nextSmaller= getNextSmallerHeight(height, n);
        
        int area = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int len = height[i];
            
            if (nextSmaller[i] == -1) {
                nextSmaller[i] = n;
            }
            
            int wid = nextSmaller[i] - prevSmaller[i] - 1;
            
            int newArea = len * wid;
            
            area = max(area, newArea);
        }
        
        return area;
    }
    
  public:
    // TC = O(N * M)
    // SC = O(M)
    int maxArea(int M[MAX][MAX], int n, int m) {
        // store the height of each column
        vector<int> height(m, 0);
        
        int ans = INT_MIN;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                
                if (M[row][col] == 1) {
                    height[col]++;
                }
                else height[col] = 0;
            }
            ans = max(ans, getLargestArea(height));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends