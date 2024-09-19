// https://leetcode.com/problems/linked-list-cycle-ii/



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
    // TC : O(N)
    // SC : O(N)
    ListNode* approach_1(ListNode* head) {
        if (!head || !head -> next) return NULL;    // No Cycle : empty list or has only single node

        unordered_map<ListNode*, bool> visited; // {Node, {visited, position}}
        ListNode* temp = head;

        while (temp) {
            if (visited[temp]) {
                return temp;
            }
            visited[temp] = 1;
            temp = temp -> next;
        }
        return NULL;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_2(ListNode* head) {
        if (!head || !head -> next) 
            return NULL;    // No Cycle if list is empty or has only one node

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (fast == slow) { // Cycle Present
                fast = head;
                while (slow != fast) {  // Find pos of cycle
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        
        return NULL; // No cycle found
    }
public:
    ListNode *detectCycle(ListNode *head) {
        // return approach_1(head);   // HashMap Used

        return approach_2(head);      // Hare and Tortoise Appr.
    }
};