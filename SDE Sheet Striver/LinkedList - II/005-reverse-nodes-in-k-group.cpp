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

    ListNode* getKthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp && cnt < k) {
            temp = temp -> next;
            cnt ++;
        }
        return temp;
    }

    ListNode* reverseGroup(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        while (curr) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    // TC : O(2N)
    // SC : O(1)
    ListNode* approach_2(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* kthNode = getKthNode(temp, k);

            if (!kthNode) {
                if (prev) prev -> next = temp;  // check prev exist : 1 -> 2 and K = 3
                break;  // No More LL left for reversal
            }

            ListNode* forw  = kthNode -> next;
            kthNode -> next = NULL;

            reverseGroup(temp);
            
            if (temp == head) { // first group of reversed LL
                head = kthNode;
            } else {
                prev -> next = kthNode;
            }

            prev = temp;
            temp = forw;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // return approach_1(head, k);  // Recursive 

        return approach_2(head, k);  // Iterative 
    }
};