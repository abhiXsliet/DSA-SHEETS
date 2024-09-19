// https://leetcode.com/problems/reverse-nodes-in-k-group/



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
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            head = head -> next;
            len ++;
        }
        return len;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_1(ListNode* head, int k) {
        if (!head || !head -> next) return head;

        int len = getLen(head);
        if (len < k) return head;   // check if fewer nodes than k

        ListNode* prev = NULL;
        ListNode* forw = NULL;
        ListNode* curr = head;
        int cnt = 1;

        while (cnt <= k && curr) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
            cnt ++;
        }

        // we can use args as : forw or curr both
        if (forw) head -> next = approach_1(forw, k);   

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return approach_1(head, k);  // Recursive 

        // return approach_2(head, k);  // Iterative pending ??
    }
};