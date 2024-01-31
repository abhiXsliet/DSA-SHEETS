// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    // TC = O(N)
    // SC = O(N)
    bool solve_way_1(string x) {
        stack<char> stk;
        int n = x.length();
        
        for (int i = 0; i < n; i++) {
            char ch = x[i];
            
            if (stk.empty() || ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
                
            }
            else {
                char topCh = stk.top();
                
                if(!stk.empty() && 
                  (topCh == '(' && ch == ')' || 
                   topCh == '{' && ch == '}' || 
                   topCh == '[' && ch == ']')) {
                    
                    stk.pop();
                    if(!stk.empty())
                        topCh = stk.top();
                }
                else return false;
            }
        }
        
        return stk.empty();
    }
    
    // TC = O(N)
    // SC = O(N)
    bool solve_way_2(string x) {
        int n = x.length();
        
        stack<char>stk;
        
        for (int i = 0; i < n; i++) {
            char ch = x[i];
            
            if (ch == '(' || ch == '{' || ch == '[') 
                stk.push(ch);
            else {
                if (stk.empty()) return false;
                
                char topCh = stk.top();
                stk.pop();
                
                if ((topCh == '(' && ch != ')') || 
                    (topCh == '{' && ch != '}') || 
                    (topCh == '[' && ch != ']')) {
                       
                    return false;
                }
            }
        }
        
        return stk.empty();
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // return solve_way_1(x);
        
        return solve_way_2(x);
    }
};


//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends