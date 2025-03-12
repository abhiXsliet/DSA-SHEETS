// https://www.naukri.com/code360/problems/sort-a-stack_985275




#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N) Recursive Stack Space
void insertSorted(stack<int>& stk, int val) {
    if (stk.empty() || stk.top() < val) {
        stk.push(val);
        return;
    }

    int num = stk.top();
    stk.pop();

    insertSorted(stk, val);
    stk.push(num);
}

// TC : O(N^2)
// SC : O(N) Recursive stack space
void approach_1(stack<int> &stk) {
    if (stk.empty()) return;

    int val = stk.top();
    stk.pop();

    approach_1(stk);
    insertSorted(stk, val);
}

// TC : O(N^2)
// SC : O(N)
void approach_2(stack<int> &stk) {
    stack<int> newStk;
    while (!stk.empty()) {
        int val = stk.top();
        stk.pop();
        while (!newStk.empty() && newStk.top() < val) {
            stk.push(newStk.top());
            newStk.pop();
        }
        newStk.push(val);
    }
    
    while (!newStk.empty()) {
        stk.push(newStk.top());
        newStk.pop();
    }
}

void sortStack(stack<int> &stk) {
	// approach_1(stk); // Recursive
    approach_2(stk); // Iterative
}