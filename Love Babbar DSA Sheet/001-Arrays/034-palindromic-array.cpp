// https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1


//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
// } Driver Code Ends
/*Complete the function below*/

class Solution {
private:
    bool isPalindrome(string str) {
        int i = 0, j = str.length() - 1;
        while(i <= j) {
            if(str[i] == str[j]) {
                i++, j--;
            }
            else return false;
        }
        return true;
    }
public:
    int PalinArray(int a[], int n)
    {
    	for (int i = 0; i < n; i++) {
    	    string str = to_string(a[i]);
    	    if(!isPalindrome(str)) return 0;
    	}
    	return 1;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends