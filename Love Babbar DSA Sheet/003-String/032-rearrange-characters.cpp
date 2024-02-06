// https://www.geeksforgeeks.org/problems/rearrange-characters4649/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

class Solution {
    private:
    // TC : O(N*logN)
    // SC : O(N) -> map could be holding only 26 lowercase english alphabets
    string solve_approach_1(string& s) {
        unordered_map<char, int> mpp;
        for (char& ch : s) mpp[ch] ++;
        
        int max_char_cnt = max_element(begin(mpp), end(mpp), [&](auto a, auto b) {
            return a.second < b.second; // maxOccuring char
        }) -> second;
        
        if (max_char_cnt > (s.length() + 1) / 2) return "-1";
        
        priority_queue<pair<int, char>> pq;
        for (auto& it : mpp) {
            pq.push({it.second, it.first});
        }
        
        pair<int, char> prev = {-1, '#'};
        string result;
        
        while(!pq.empty()) {
            pair<int, char> curr = pq.top();
            pq.pop();
            
            result += curr.second;
            curr.first --;
            
            if (prev.first > 0) 
                pq.push(prev);
           
            prev = curr;
        }
        return result;
    }
    
    
    // TC : O(N)
    // SC : O(N) -> map could be holding only 26 lowercase english alphabets
    string solve_approach_2(string& str) {
        int n = str.length();
        unordered_map<char, int> mpp;
        for (char& ch : str) 
            mpp[ch] ++;
        
        // Find the character with maximum frequency
        char max_ch = max_element(mpp.begin(), mpp.end(), [&](auto a, auto b){
            return a.second < b.second; 
        })->first;
        
        if(mpp[max_ch] > (n+1)/2)
            return "-1";
        
        // Fill the even index positions with the maximum frequency character
        string result(n, ' ');
        for (int i = 0; i < n; i += 2) {
            if (mpp[max_ch] > 0) {
                result[i] = max_ch;
                mpp[max_ch]--;
            } else {
                break;
            }
        }
        
        // Fill the remaining even positions and then odd positions with the remaining characters
        for (int i = 0; i < n; i += 2) {
            for (auto& it : mpp) {
                if (it.second > 0 && result[i] == ' ') {
                    result[i] = it.first;
                    it.second--;
                    break;
                }
            }
        }
        for (int i = 1; i < n; i += 2) {
            for (auto& it : mpp) {
                if (it.second > 0) {
                    result[i] = it.first;
                    it.second--;
                    break;
                }
            }
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(26) ~= O(1) 
    string solve_approach_3(string& str) {
        int n = str.length();
        vector<int> freq(26, 0);
        for (char& ch : str) 
            freq[ch - 'a'] ++;
        
        // Find index o fthe character with maximum frequency 
        int max_ch = max_element(begin(freq), end(freq)) - begin(freq);
        
        if(freq[max_ch] > (n+1)/2)
            return "-1";
        
        // Fill the even index positions with the maximum frequency character
        string result(n, ' ');
        for (int i = 0; i < n; i += 2) {
            if (freq[max_ch] > 0) {
                result[i] = max_ch + 'a';
                freq[max_ch]--;
            } else {
                break;
            }
        }
        
        // Fill the remaining even positions and then odd positions with the remaining characters
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > 0 && result[i] == ' ') {
                    result[i] = j + 'a';
                    freq[j]--;
                    break;
                }
            }
        }
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > 0) {
                    result[i] = j + 'a';
                    freq[j]--;
                    break;
                }
            }
        }
        return result;
    }
    public:
    string rearrangeString(string str)
    {
        // return solve_approach_1(str);
        
        // return solve_approach_2(str);
        
        return solve_approach_3(str);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends