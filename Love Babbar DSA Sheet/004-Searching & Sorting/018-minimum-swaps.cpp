// https://www.geeksforgeeks.org/problems/minimum-swaps/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    private:
    // TC : O(N * log(N))
    // SC : O(N)
    int solve_approach_1(vector<int>& nums, int n) {
        vector<pair<int, int>> store(n);    // {element, idx}
        for (int i = 0; i < n; i++) {
            store[i] = {nums[i], i};
        }
        
        sort(begin(store), end(store));
        
        int minSwaps = 0;
        for (int i = 0; i < n; i++) {
            auto p = store[i];
            
            int val = p.first;
            int idx = p.second;
            
            if (i != idx) {
                minSwaps ++;
                swap(store[i], store[idx]);
                i --;
            }   
        }
        return minSwaps;
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    int solve_approach_2(vector<int>& nums, int n) {
        vector<pair<int, int>> store(n);    // {element, idx}
        for (int i = 0; i < n; i++) {
            store[i] = {nums[i], i};
        }
        
        sort(begin(store), end(store));
        
        vector<bool> vis(n, 0);
        int minSwaps = 0;
        for (int i = 0; i < n; i++) {
            auto p = store[i];
            
            int val = p.first;
            int idx = p.second;
            
            if (idx == i || vis[i] == true)
                continue;
            
            int cycleLen = 0;
            int j = i;
            while (vis[j] == false) {
                cycleLen ++;
                vis[j]  = 1;
                j = store[j].second;
            }
            minSwaps += (cycleLen - 1);
        }
        return minSwaps;
    }
    
    // TC : O(N * log(N))
    // SC : O(N)
    int solve_approach_3(vector<int>& nums, int n) {
        unordered_map<int, int> mpp; // {num, idx}
        
        vector<int> store(begin(nums), end(nums));
        
        sort(begin(store), end(store));
        
        for (int i = 0; i < n; i++) 
            mpp[store[i]] = i;
        
        int minSwaps = 0;
        for (int i = 0; i < n; i++) {
            if (i != mpp[nums[i]]) {
                minSwaps ++;
                swap(nums[i], nums[mpp[nums[i]]]);
                i --;
            }
        }
        return minSwaps;
    }
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
        // return solve_approach_1(nums, nums.size());
        
        // return solve_approach_2(nums, nums.size());
        
        return solve_approach_3(nums, nums.size());
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends