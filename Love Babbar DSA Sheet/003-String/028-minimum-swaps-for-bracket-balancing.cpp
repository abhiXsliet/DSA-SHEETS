// https://www.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{ 
private:
    // TC : O(N^2)
    // SC : O(1)
    int solve_brute(string& s, int n) {
        if (n % 2 != 0) return 0;
        
        // to store the count of '['
        int count  = 0;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') count ++;
            else count --;
            
            // this means we must start swapping
            if (count < 0) {
                
                // j holds the index of '['
                int j = i + 1;
                
                while (j < n) {
                    if (s[j] == '[') break;
                    j++;
                }
                
                // increment result
                result += j - i;
                
                // set count to 1
                count = 1;
                
                //Bring character at jth position to ith position
                // and shift all character from i to j-1 towards right 
                char ch = s[j];
                for (int k = j; k > i; k--) {
                    s[k] = s[k - 1];
                }
                s[i] = ch;
            }
        }
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_better(string s, int n) {
        vector<int> store;  // to keep track of indices '['
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') 
                store.push_back(i);
        }
        
        // to keep track of encountered '['
        int cnt = 0;
        // to keep track of position of next '[' in store
        int pos = 0;    // this works as j of brute force
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] == '[') {
                cnt++;
                pos++;
            }
            else cnt --;
            
            // We have encountered an unbalanced part of string
            if (cnt < 0) { // we must start swapping
                
                ans += store[pos] - i;
                swap(s[i], s[store[pos]]);
                pos ++;
                
                // reset cnt to 1
                cnt = 1;
            }
        }
        
        return ans;
    }
    
    // TC : O(N)
    // SC : O(1)
    int solve_optimal(string s, int n) {
        int openBrac  = 0;
        int closeBrac = 0;
        
        int imbalance = 0;
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] == '[') {
                
                openBrac ++;
                
                if (imbalance > 0) {
                    result += imbalance;
                    
                    // imbalance decremented by 1 as it solved
                    // only one imbalance of Left and Right
                    imbalance --;
                }
            }
            else {
                
                closeBrac ++;
                
                imbalance = (closeBrac - openBrac);
            }
        }
        
        return result;
    }
public:
    int minimumNumberOfSwaps(string S){
        // return solve_brute(S, S.length());
        
        // return solve_better(S, S.length());
        
        return solve_optimal(S, S.length());
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends