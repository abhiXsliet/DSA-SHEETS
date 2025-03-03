// https://www.geeksforgeeks.org/problems/aggressive-cows/0



//{ Driver Code Starts
// Initial function template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    bool isPossible(vector<int> &stalls, int k, int limitDist) {
        int prevStall = stalls[0];
        int placedCow = 1;
        for (int i = 1; i < stalls.size(); i ++) {
            if (abs(prevStall - stalls[i]) >= limitDist) {
                prevStall = stalls[i];
                placedCow += 1;
            } 
        }
        return placedCow >= k;
    }
  
    // TC : O(N*log(N) + N*max_element)
    // SC : O(1)
    int approach_1(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(begin(stalls), end(stalls));
        int low = 0, high = *max_element(begin(stalls), end(stalls));
        int ans = 0;
        for (int i = high; i >= low; i --) {
            if (isPossible(stalls, k, i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_2(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(begin(stalls), end(stalls));
        int low = 0, high = *max_element(begin(stalls), end(stalls));
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // return approach_1(stalls, k);
        return approach_2(stalls, k);
    }
};


//{ Driver Code Starts.
int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends