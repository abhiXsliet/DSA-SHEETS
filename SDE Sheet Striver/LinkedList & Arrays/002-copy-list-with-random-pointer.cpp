// https://leetcode.com/problems/copy-list-with-random-pointer/




#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    Node* solve(Node* head) {
        if (!head) return NULL;

        // Mapping original node to their copies
        unordered_map<Node*, Node*> mpp;

        Node* temp    = head;
        Node* newNode = new Node(-1);   // Dummy node
        Node* newHead = newNode;
        
        // 1st pass: Create a deep copy of the linked list (without random pointers)
        while (temp) {
            Node* add = new Node(temp -> val);
            newNode -> next = add;

            mpp[temp] = add;    // track every new Node made corresponding to original node 

            temp    = temp -> next;
            newNode = newNode -> next;
        }

        newNode = newHead -> next; // Point newNode to the start of the deep copied list
        temp    = head;            // Reset temp to the head of the original list
        
        // 2nd pass: Assign the random pointers
        while (temp) {
            if (temp -> random) {
                newNode -> random = mpp[temp -> random];  // corresponding node of temp
            } else {
                newNode -> random = NULL;
            }
            temp    = temp -> next;
            newNode = newNode -> next;
        }
        
        // Remove dummy node
        temp = newHead;
        newHead = newHead -> next;
        delete temp;

        return newHead;
    }

    // TC : O(N)
    // SC : O(1)
    Node* optimal(Node* head) {
        if (!head) return NULL;

        // 1 : Insert the clone node b/w original nodes
        Node* curr = head;
        while (curr) {
            Node* newN   = new Node(curr -> val);
            Node* forw   = curr -> next;
            curr -> next = newN;
            newN -> next = forw;

            curr = forw;
        }
        
        // 2. Assign Random pointer
        curr = head;
        while (curr) {
            if (curr -> random) {
                curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }

        // 3. Separate the cloned LL from original LL
        Node* original = head;
        Node* copied   = head -> next;
        Node* newHead  = copied;

        while (original && copied) {
            original -> next = copied -> next;
            original = original -> next;

            if (original) 
                copied -> next = original -> next;
            copied = copied -> next;
        }

        return newHead;
    }
public:
    Node* copyRandomList(Node* head) {
        // return solve(head);

        return optimal(head);
    }
};