// https://leetcode.com/problems/lru-cache/




#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------- APPROACH - 1 : BRUTE(TLE) --------------------------------------------------------------------
// TC : O(N^2) for both put and get method if gets called N-times
// SC : O(N)
class LRUCache {
    public:
    vector<pair<int, int>> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int val = -1;
        for (int i = 0; i < cache.size(); i ++) { // O(N)
            if (cache[i].first == key) {
                val = cache[i].second;
                cache.erase(begin(cache) + i);    // O(N)
                cache.push_back({key, val});  // make it as a least recently used item
            }
        }
        return val;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i ++) {
            if (cache[i].first == key) {
                cache.erase(begin(cache) + i);
                break;
            }
        }
        if (cache.size() == cap) {
            cache.erase(begin(cache));
        }
        cache.push_back({key, value});
    }
};    


// -------------------------------------------------------- APPROACH - 2 : OPTIMAL (used list and map<pair<int, pair<list<int>::iterator, int>>> mpp {key, {addreess-of-key, value}}) --------------------------------------------------------------------
// TC : O(N) for both put and get method
// SC : O(N)
class LRUCache {
    public:
    list<int> dll;  // key
    map<int, pair<list<int>::iterator, int>> mpp;   // {key, {address-of-dll, value}}
    int cap;
    LRUCache(int capacity) {
        mpp.clear();
        cap = capacity;
    }

    void mostRecentlyUsed(int key) {
        // delete the entry from dll and push it at the front
        dll.erase(mpp[key].first);  // mpp[key].first -> gives the address to erase in dll
        
        dll.push_front(key);    // O(1) : make key as most recently used

        // change the address of key in map (after getting inserted at front as it became mru)
        mpp[key].first = dll.begin();
    }
    
    int get(int key) {
        if (mpp.count(key)) {
            // get the val
            int val = mpp[key].second;

            // make key as most recently used (mru)
            mostRecentlyUsed(key);

            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.count(key)) {
            // update the value for key 
            mpp[key].second = value;

            // make it most recently used
            mostRecentlyUsed(key);
        } else {
            if (cap == mpp.size()) {
                // remove lru
                int keyToDelete = dll.back();
                dll.pop_back();      // O(1)

                mpp.erase(keyToDelete); // remove the entry from map also
            }

            // create a new node at the front of dll
            dll.push_front(key);

            // insert the newly made node to the mpp
            mpp[key] = {dll.begin(), value};
        }
    }
};

// -------------------------------------------------------- APPROACH - 2 : OPTIMAL (used list and map<pair<int, pair<list<int>::iterator, int>>> mpp {key, {addreess-of-key, value}}) --------------------------------------------------------------------
// TC : O(N) for both put and get method
// SC : O(N)
class Node {
public:
    Node *next, *prev;
    int key, value;
    Node(int k, int v) {
        key   = k;
        value = v;
        next  = NULL;
        prev  = NULL;
    }
};

class LRUCache {
private:
    Node* head; // head helps to insert a new node after the head
    Node *tail; // tails tracks the lru-node to be deleted 
    int cap;
    unordered_map<int, Node*> mpp;

    void removeNode(Node* node) {
        Node* forw   = node -> next;
        Node* back   = node -> prev;
        if (back) back -> next = forw;
        if (forw) forw -> prev = back;
    }

    // Insert a node after the head
    void addNode(Node* node) {
        node -> next = head -> next;
        node -> prev = head;
        if (head -> next) head -> next -> prev = node;
        head -> next = node;
    }
public:
    LRUCache(int capacity) {
        mpp.clear();
        cap  = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (mpp.count(key)) {
            // make this key as the mru (most recent used)
            Node* recent = mpp[key];

            // Move node to Most Recently Used (MRU) position
            removeNode(recent);     // remove 'recent' node from the current position
            addNode(recent);        // add 'recent' node in the start of list making it mru-node

            return recent -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.count(key)) {
            // update key with lastest value
            Node* recent = mpp[key];
            recent -> value = value;     // update recent value

            // make 'recent' node as mru
            removeNode(recent);
            addNode(recent);
        } else {
            if (mpp.size() == cap) {    // delete the lru-node from tail
                Node* nodeToDel = tail -> prev; // tail is pointing to -1 & tail -> prev pointing to last node
                removeNode(nodeToDel);          // remove from list
                mpp.erase(nodeToDel -> key);    // remove the key from mpp
                delete nodeToDel;
            }

            // Add a new Node
            Node* newNode = new Node(key, value);
            addNode(newNode);
            mpp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */