// https://leetcode.com/problems/implement-stack-using-queues/



#include <bits/stdc++.h>
using namespace std;

// TC : O(N) push & all other O(1)
// SC : O(N) space used by queue
class MyStack {
public:
    queue<int> q;
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i ++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty() ? 1 : 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */