// https://practice.geeksforgeeks.org/problems/word-wrap1646/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int t[501][2001];
    
    int solve_rec(vector<int>& nums, int idx, int vacancy, int& k) {
        if (idx == nums.size())
            return 0;
            
        int ans = 0;
        
        // if remaining spaces is less than the word itself
        // then pay the cost and move to the next line 
        // and include that word which results in reduction of total spaces 
        // then vacant places for next word = total spaces - word.length - 1 
        if (nums[idx] > vacancy) {
            ans = (vacancy + 1) * (vacancy + 1) + solve_rec(nums, idx+1, k - nums[idx] - 1, k);
        }
        else {
            // if the current line not fits the word 
            // then pay the cost for remaining spaces and include word in the next line
            // and we left with vacant places = total spaces - word.length - 1
            int option1 = (vacancy + 1) * (vacancy + 1) + solve_rec(nums, idx+1, k - nums[idx] - 1, k);
            
            // if the current line fits the word 
            // then take it without paying any cost and reduce the vacant places
            int option2 = solve_rec(nums, idx+1, vacancy - nums[idx] - 1, k);
            
            ans = min(option1, option2);
        }
        
        return ans;
    }
    
    // TC = O(N * K)
    // SC = O(N * K)
    int solve_mem(vector<int>& nums, int idx, int vacancy, int& k) {
        if (idx == nums.size())
            return 0;
            
        if (t[idx][vacancy] != -1) 
            return t[idx][vacancy]; 
            
        int ans = 0;
        
        // if remaining spaces is less than the word itself
        // then pay the cost and move to the next line 
        // and include that word which results in reduction of total spaces 
        // then vacant places for next word = total spaces - word.length - 1 
        if (nums[idx] > vacancy) {
            ans = (vacancy + 1) * (vacancy + 1) + solve_mem(nums, idx+1, k - nums[idx] - 1, k);
        }
        else {
            // if the current line not fits the word 
            // then pay the cost for remaining spaces and include word in the next line
            // and we left with vacant places = total spaces - word.length - 1
            int option1 = (vacancy + 1) * (vacancy + 1) + solve_mem(nums, idx+1, k - nums[idx] - 1, k);
            
            // if the current line fits the word 
            // then take it without paying any cost and reduce the vacant places
            int option2 = solve_mem(nums, idx+1, vacancy - nums[idx] - 1, k);
            
            ans = min(option1, option2);
        }
        
        return t[idx][vacancy] = ans;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // return solve_rec(nums, 0, k, k);
        
        memset(t, -1, sizeof(t));
        return solve_mem(nums, 0, k, k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends