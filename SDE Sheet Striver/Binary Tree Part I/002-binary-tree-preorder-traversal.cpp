// https://leetcode.com/problems/binary-tree-preorder-traversal/




#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void solve(TreeNode* root, vector<int> &result) {
        if (!root) return;

        result.push_back(root -> val);
        solve(root -> left, result);
        solve(root ->right, result);
    }
    
    // TC : O(N)
    // SC : O(H) for skew tree or O(log(N)) for balanced tree
    vector<int> approach_1(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        while (!stk.empty() || curr) {
            while (curr) {
                stk.push(curr);
                result.push_back(curr -> val);
                curr = curr -> left;
            }

            curr = stk.top();
            stk.pop();

            curr = curr -> right;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(H) for skew tree or O(log(N)) for balanced tree
    vector<int> approach_2(TreeNode* root) {
        if (!root) return {};

        vector<int> result;
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();

            result.push_back(curr -> val);

            if (curr -> right) stk.push(curr ->right);
            if (curr -> left)  stk.push(curr -> left);
        }
        return result;
    }

    // TC : O(N)
    // SC : O(H) for skew tree or O(log(N)) for balanced tree
    vector<int> approach_3(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // return approach_1(root); // Iterative
        // return approach_2(root); // Iterative : differently written
        return approach_3(root); // Recursive
    }
};