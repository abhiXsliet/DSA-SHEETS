// https://www.geeksforgeeks.org/problems/print-anagrams-together/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  private:
    // TC : O(N * Mlog(M)) Where N = Input vector of strings size & M = Max Length of individual string
    // SC : O(N)
    vector<vector<string>> solve_approach_1(vector<string>& string_list) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;
        
        for (string& s : string_list) {
            
            string str = s;
            sort(begin(str), end(str));
            mpp[str].push_back(s);
        }
        
        for (auto& it : mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
    
    // TC : O(M) Where M = Max Length of the string
    // SC : O(1)
    // function to get the sorted string
    string getString(string& s) {
        vector<char> temp(26, 0);
            
        string str = s;
        for (char& ch : str) {
            temp[ch - 'a'] ++;
        }
        
        string new_str;
        for (int i = 0; i < 26; i++) {
            int val = temp[i];
            new_str += val + i + 'a';
        }
        
        return new_str;
    }
    
    // TC : O(N * M) Where N = Input string_list size & M = Max Len of individual string
    // SC : O(N)
    vector<vector<string>> solve_approach_2(vector<string>& string_list) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mpp;
        
        for (string& s : string_list) {
            
            string new_str = getString(s);
            mpp[new_str].push_back(s);
        }
        
        for (auto& it : mpp) {
            result.push_back(it.second);
        }
        return result;
    }
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        // return solve_approach_1(string_list);
        
        return solve_approach_2(string_list);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends