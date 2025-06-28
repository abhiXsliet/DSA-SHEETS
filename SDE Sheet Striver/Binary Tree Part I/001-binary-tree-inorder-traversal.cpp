// https://leetcode.com/problems/binary-tree-inorder-traversal/




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

        solve(root -> left, result);
        result.push_back(root -> val);
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
                curr = curr -> left;
            }

            curr = stk.top();
            stk.pop();

            result.push_back(curr -> val);

            curr = curr -> right;
        }
        return result;
    }

    // TC : O(N)
    // SC : O(H) for skew tree or O(log(N)) for balanced tree
    vector<int> approach_2(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // return approach_1(root);    // Iterative
        return approach_2(root);    // Recursive
    }
};