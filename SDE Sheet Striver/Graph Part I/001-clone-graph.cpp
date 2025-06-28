// https://leetcode.com/problems/clone-graph/




#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    void BFS(Node* original, unordered_map<Node*, Node*> &mpp) {
        queue<Node*> q;
        q.push(original);
        while (!q.empty()) {
            Node* fNode = q.front();
            Node* cloned = mpp[fNode];
            q.pop();

            for (auto &origNbr : fNode -> neighbors) {
                if (!mpp.count(origNbr)) {
                    Node* clonedNbr  = new Node(origNbr -> val);
                    mpp[origNbr] = clonedNbr;

                    cloned -> neighbors.push_back(clonedNbr);
                    q.push(origNbr);

                } else {
                    cloned -> neighbors.push_back(mpp[origNbr]);
                }
            }
        }
    }

    void DFS(Node* cloned, Node* original, unordered_map<Node*, Node*> &mpp) {
        for (auto &origNbr : original -> neighbors) {
            if (!mpp.count(origNbr)) {
                Node* clonedNbr  = new Node(origNbr -> val);
                mpp[origNbr] = clonedNbr;

                cloned -> neighbors.push_back(clonedNbr);
                DFS(clonedNbr, origNbr, mpp);
            } else {
                cloned -> neighbors.push_back(mpp[origNbr]);
            }
        }
    }

    // TC : O(N)
    // SC : O(N)
    Node* approach_1(Node* node) {
        if (!node) return NULL;
        Node* cloned = new Node(node -> val);
        unordered_map<Node*, Node*> mpp;    // {Original-Node-Add, Cloned-Node-Add.}
        mpp[node] = cloned;   
        DFS(cloned, node, mpp);
        return cloned;
    }

    // TC : O(N)
    // SC : O(N)
    Node* approach_2(Node* node) {
        if (!node) return NULL;
        Node* cloned = new Node(node -> val);
        unordered_map<Node*, Node*> mpp;    // {Original-Node-Add, Cloned-Node-Add.}
        mpp[node] = cloned;   
        BFS(node, mpp);
        return cloned;
    }
public:
    Node* cloneGraph(Node* node) {
        // return approach_1(node);    // DFS
        return approach_2(node);    // BFS
    }
};