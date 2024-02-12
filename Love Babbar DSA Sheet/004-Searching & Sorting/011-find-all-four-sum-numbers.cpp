// https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    // TC : O(N^3 * log(N))
    // SC : O(N) -> set store vectors of 4-length
    vector<vector<int>> approach_1(vector<int>& nums, int K) {
        set<vector<int>> store;
        int n  = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                set<int> st;
                for (int k = j + 1; k < n; k++) {
                    
                    int sum = nums[i] + nums[j] + nums[k];
                    int ele = K - sum;
                    
                    if (st.find(ele) != st.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], ele};
                        sort(begin(temp), end(temp));
                        store.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>result (begin(store), end(store));
        return result;
    }
    
    // TC : O(N^3)
    // SC : O(1) + O(no. of quadruples) -> to return answer
    vector<vector<int>> approach_2(vector<int>& nums, int K) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < n - 2; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            
            for (int j = i + 1; j < n - 1; j++) {
                
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == K) {
                        
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(begin(temp), end(temp));
                        result.push_back(temp);
                        
                        k ++;
                        l --;
                        
                        while (k < l && nums[k] == nums[k - 1]) k ++;
                        while (k < l && nums[l] == nums[l + 1]) l --;
                    }
                    else if (sum < K) {
                        k ++;
                    }
                    else {
                        l --;
                    }
                }
            }
        }
        
        return result;
    }
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &nums, int k) {
        // return approach_1(nums, k);
        
        return approach_2(nums, k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends