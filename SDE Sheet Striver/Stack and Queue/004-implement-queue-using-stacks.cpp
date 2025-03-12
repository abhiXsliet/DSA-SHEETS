// https://leetcode.com/problems/implement-queue-using-stacks/



#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------- APPROACH - 1 : Expensive Push Operation ----------------------------------------------------
// TC : O(N^2) for push & O(1) for peek and pop
// SC : O(N)
class MyQueue {
    public:
    stack<int> stk1, stk2;
    MyQueue() {}
    
    void push(int x) {
        if (stk1.empty()) {
            stk1.push(x);
        } else {
            while(stk1.size()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            stk1.push(x);
            while (stk2.size()) {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
    }
    
    int pop() {
        if (stk1.empty()) return -1;
        int val = stk1.top();
        stk1.pop();
        return val;
    }
    
    int peek() {
        return stk1.empty() ? -1 : stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};

// ----------------------------------------------------- APPROACH - 2 : Optimized Push Operation O(1) ----------------------------------------------------
// TC : O(1) for push & O(N) for pop and peek
// SC : O(N)
class MyQueue {
    public:
    stack<int> stk1, stk2;
    MyQueue() {}
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (!stk2.empty()) {
            int val = stk2.top();
            stk2.pop();
            return val;
        } else {
            while (stk1.size()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            if (stk2.size()) {
                int val = stk2.top();
                stk2.pop();
                return val;
            }
        }
        return -1;
    }
    
    int peek() {
        if (!stk2.empty()) {
            return stk2.top();
        } else {
            while (stk1.size()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            if (stk2.size()) {
                return stk2.top();
            }
        }
        return -1;
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */