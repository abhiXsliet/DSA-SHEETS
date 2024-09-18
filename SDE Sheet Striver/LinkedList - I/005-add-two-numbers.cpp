// https://leetcode.com/problems/add-two-numbers/



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
    // TC : O(M + N) Where M = l1.length, N = l2.length
    // SC : O(1)
    ListNode* approach_1(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* temp   = result;

        while(l1 && l2) {
            int sum = l1 -> val + l2 -> val + carry;
            carry = sum / 10;
            sum  %= 10;

            temp -> next = new ListNode(sum);
            temp = temp -> next;
            l1   = l1   -> next;
            l2   = l2   -> next;
        }
        while (l1) {
            int sum = l1 -> val + carry;
            carry = sum / 10;
            sum  %= 10;
            
            temp -> next = new ListNode(sum);
            temp = temp -> next;
            l1   = l1   -> next;
        }
        while (l2) {
            int sum = l2 -> val + carry;
            carry = sum / 10;
            sum  %= 10;
            
            temp -> next = new ListNode(sum);
            temp = temp -> next;
            l2   = l2   -> next;
        }
        if (carry > 0) 
            temp -> next = new ListNode(carry);
            
        return result -> next;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_2(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp  = dummy;
        
        while (l1 || l2 || carry) {
            int d1 = l1 != NULL ? l1 -> val : 0;
            int d2 = l2 != NULL ? l2 -> val : 0;

            int sm = d1 + d2 + carry;
            carry  = sm / 10;
            sm    %= 10;

            ListNode* newNode = new ListNode(sm);
            temp -> next = newNode;
            temp = temp -> next;
            
            l1   = l1 != NULL ? l1 -> next : NULL;
            l2   = l2 != NULL ? l2 -> next : NULL;
        }

        ListNode* result = dummy -> next;
        delete dummy;
        return result;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return approach_1(l1, l2);

        return approach_2(l1, l2);  // ONE PASS
    }
};