// https://leetcode.com/problems/linked-list-cycle/



#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {  
private:
    // TC = O(N)
    // SC = O(N)
    bool approach_1(ListNode* head) {
        unordered_map<ListNode*, bool> visited;

        if (head == NULL) 
            return false;

        ListNode* temp = head;
        while(temp != NULL) {
            if(visited[temp]) 
                return true;

            visited[temp] = 1;

            temp = temp -> next;
        }
        return false;
    }

    // TC = O(N)
    // SC = O(1)
    // Floyd Cycle Detection Algo
    bool approach_2(ListNode* head) {
        if(!head) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        if(!slow -> next || !fast -> next) 
            return false;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if (slow == fast) return true;
        }
        return false;
    }

    
public:
    bool hasCycle(ListNode *head) {
        // return approach_1(head);     // HashMap

        return approach_2(head);     // Hare and tortoise approach
    }
};