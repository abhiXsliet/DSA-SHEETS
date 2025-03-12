#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node *next;
    Node (int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

class Stack {
    public :
    Node *head;
    Stack() {
        head = NULL;
    }

    void push (int d) {
        Node *newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }

    int pop () {
        if (head == NULL) return -1;
        int val  = head -> data;
        Node *temp = head;
        head = head -> next;
        delete temp;
        return val; // returning popped value
    }

    int peek() {
        if (head == NULL) return -1;
        return head -> data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    // Creating a stack
    Stack st;

    // Push elements onto the stack
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;
    return 0;
}