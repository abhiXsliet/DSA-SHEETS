// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}
// } Driver Code Ends

/* Node structure  used in the program
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  private:
    // TC : O(N1 + N2)      Where N1, N2 = Length of List1, List2 respectively
    // SC : O(max(N1, N2)) 
    Node* mergeTwoSortedLL(Node* h1, Node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        
        Node* result;
        if (h1 -> data <= h2 -> data) {
            result = h1;
            result -> bottom = mergeTwoSortedLL(result -> bottom, h2);
        } else {
            result = h2;
            result -> bottom = mergeTwoSortedLL(h1, result -> bottom);
        }
        return result;
    }
    
    // TC : O(N1 + N2) Where N1, N2 = Length of List1, List2 respectively
    // SC : O(max(N1, N2)) 
    Node* mergeTwoSortedList(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while (l1 && l2) {
            if (l1 -> data < l2 -> data) {
                temp -> bottom = l1;
                temp = l1;
                l1 = l1 -> bottom;
            } else {
                temp -> bottom = l2;
                temp = l2;
                l2 = l2 -> bottom; 
            }
        }
        
        // Attach Remaining LL
        if (l1) temp -> bottom = l1;
        if (l2) temp -> bottom = l2;
        
        return ans -> bottom;
    }
  public:
    // TC : O(M * N * N) Where M = Average Length of LL & N = Total No. of Nodes of LL
    // SC : O(M * N) Recursive Stack Space
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if (!root) return NULL;
        
        Node* root_2 = flatten(root -> next);
        
        return mergeTwoSortedLL(root, root_2);   // Recursive
        // return mergeTwoSortedList(root, root_2); // Iterative
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}
// } Driver Code Ends