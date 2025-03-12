// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};
// } Driver Code Ends

// Function to push an integer into the stack.
void MyStack::push(int x) {
    int size = sizeof(arr) / sizeof(arr[0]);
    top ++;
    if (top >= size) return;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack::pop() {
    if (top < 0) return -1;
    int val = arr[top];
    top --;
    return val;
}

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << "\n~\n";
        delete sq;
    }
    return 0;
}
// } Driver Code Ends