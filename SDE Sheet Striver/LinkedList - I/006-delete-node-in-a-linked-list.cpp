// https://leetcode.com/problems/delete-node-in-a-linked-list/



#include <bits/stdc++.h>    
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* forw = node -> next;

        while (forw) {
            swap(curr -> val, forw -> val);
            prev = curr;
            curr = forw;
            forw = forw -> next;
        }
        prev -> next = NULL;
    }
};