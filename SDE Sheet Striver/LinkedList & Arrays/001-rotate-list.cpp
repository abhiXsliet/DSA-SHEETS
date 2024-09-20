// https://leetcode.com/problems/rotate-list/



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
        int cnt = 0;
        while(head) {
            head = head -> next;
            cnt ++;
        }
        return cnt;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_1(ListNode* head, int k) {
        if (!head || !head -> next) 
            return head;

        int len = getLen(head);

        if (k >= len) k %= len;
        if (k == 0) return head;

        int cnt = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (cnt < len - k) {
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }

        prev -> next = NULL;

        ListNode* temp = curr;
        while(temp -> next) { 
            temp = temp -> next;
        }
        temp -> next = head;
        head = curr;
        
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_2(ListNode* head, int k) {
        if (!head || !head -> next) return head;
        
        int len = getLen(head);
        
        if (k >= len) k %= len;
        if (k == 0) return head;

        ListNode* temp = head;
        while(temp -> next) {
            temp = temp -> next;
        }
        temp -> next = head;

        int cnt = 1;
        temp = head;
        while (cnt < len - k) {
            temp = temp -> next;
            cnt ++;
        }

        ListNode* forw = temp -> next;
        temp -> next = NULL;    // break circular here and make NULL
        head = forw;

        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // return approach_1(head, k);   // cut and fix reversal part of LL at start

        return approach_2(head, k);   // make a circular LL : cut and make NULL
    }
};