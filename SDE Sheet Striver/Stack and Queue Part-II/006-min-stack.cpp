// https://leetcode.com/problems/min-stack/




#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------- APPROACH : 1 (Either Use pair<int, int> or Two Stack to track the minimum) -----------------------------------------------------------------------------------
// TC : O(1)
// SC : O(1)
class MinStack {
    public:
    stack<pair<int, int>> stk;  // {val, min}
    MinStack() {}
    
    void push(int val) {
        if (stk.size()) 
            stk.push({val, min(val, stk.top().second)});    // stack has some element
        else 
            stk.push({val, val});   // stack is empty()
    }
    
    void pop() {    // operation will be called on non-empty stack
        stk.pop();
    }
    
    int top() {     // operation will be called on non-empty stack
        return stk.top().first;
    }
    
    int getMin() {  // operation will be called on non-empty stack
        return stk.top().second;
    }
};    


// ----------------------------------------- APPROACH : 2 (Encode value while pushing and popping) -----------------------------------------------------------------------------------
// If val is less than the current minimum, push the encoded value (2 * val - minimum) onto the stack.
            // This encoded value is always smaller than val, ensuring correct minimum recovery during pop operations.
            // When popping, if the top value is less than the minimum, update the minimum as: minimum = 2 * minimum - top().
// TC : O(1)
// SC : O(1)
class MinStack {
    public:
    typedef long long ll;
    ll minimum;
    stack<ll> stk;
    MinStack() {
        minimum = INT_MIN;
    }
    
    void push(int val) {
        if (stk.empty()) {  // stack is empty()
            stk.push(val);
            minimum = val;
        } else {
            if (val >= minimum) {
                stk.push(val);
            } else {    // If val < minimum, push encoded value (2 * val - minimum) and update minimum = val
                        // The encoded value is always < val, 
                        // ensuring minimum recovery while popping if top < minimum, then minimum = 2 * minimum - top()
                stk.push((ll)2*val - minimum);
                minimum = val;
            }
        }
    }
    
    void pop() {
        if (!stk.empty()) {
            ll topEl = stk.top();
            if (topEl < minimum) {  // update minimum for next set of elements from top to bottom
                minimum = 2*minimum - topEl;    
            }
            stk.pop();
        }
    }
    
    int top() {
        if (!stk.empty()) {
            ll topEl = stk.top();
            if (topEl < minimum) return minimum;
            return topEl;
        }
        return -1;
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */