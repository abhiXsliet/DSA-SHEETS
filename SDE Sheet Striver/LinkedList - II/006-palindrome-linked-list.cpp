// https://leetcode.com/problems/palindrome-linked-list/



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
    ListNode* reverse(ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode* revHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return revHead;
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_1(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast -> next) {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = NULL;

        // reverse the nodes from the slow to nullptr
        ListNode* tail = reverse(slow);

        while (head && tail) {
            if (head -> val != tail -> val)
                return false;
            head = head -> next;
            tail = tail -> next;
        }
        return true;
    }

    // TC : O(N)
    // SC : O(1)
    bool approach_2(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // REVERSE : FIRST HALF TILL MID
        while(fast && fast -> next) {
            fast = fast -> next -> next;

            ListNode* temp = slow -> next;
            slow -> next   = prev;
            prev = slow;
            slow = temp;
        }
        if (fast) { // odd case 
            slow = slow -> next;
        }
        while (prev && slow) {
            if (prev -> val != slow -> val)
                return false;
            prev = prev -> next;
            slow = slow -> next;
        }
        return true;
    }

    // TC : O(N)
    // SC : O(Recursive Depth)
    bool approach_3(ListNode* head, ListNode*& start) {
        if (!head) return true;

        bool ans = approach_3(head -> next, start);
        if (head -> val != start -> val)
            return false;
        start = start -> next;

        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        // BRUTE : Store All Values & Apply checkPalindrome Logic
        
        // return approach_1(head);        // Reverse the next half (prev, slow, fast ptr)

        // return approach_2(head);        // No need to call REVERSE fn

        return approach_3(head, head);  // No Modification in given LL
    }
};