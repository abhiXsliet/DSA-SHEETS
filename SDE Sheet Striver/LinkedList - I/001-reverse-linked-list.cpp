// https://leetcode.com/problems/reverse-linked-list/




#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
private:
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    ListNode* approach_1(ListNode* head) {
        if(!head || !head -> next) 
            return head;

        ListNode* revHead = approach_1(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return revHead;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_2(ListNode* head) {
        if (!head || !head -> next)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr != NULL) {
            ListNode* forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return approach_1(head);   // RECURSIVE

        return approach_2(head);   // ITERATIVE
    }
};