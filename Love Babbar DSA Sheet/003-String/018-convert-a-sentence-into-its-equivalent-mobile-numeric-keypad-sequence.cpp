// https://www.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1?



//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends

// TC : O(N) N = string length
// SC : O(26) ~= O(1)
string printSequence(string S)
{
    string store[] ={
                      "2", "22", "222", "3", "33", "333", "4", "44", "444", 
                      "5", "55", "555", "6", "66", "666", "7", "77", "777", 
                      "7777", "8", "88", "888", "9", "99", "999", "9999"
                    };
                    
    string result = "";
    for (char& ch : S) {
        if (ch == ' ') {
            result += '0';
        }
        else {
            int idx = ch - 'A';
            result += store[idx];
        }
    }
    return result;
}