/*
    Given the root of a binary tree, return the preorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [1,2,3]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void preorder(TreeNode * root, vector<int>& pre) {
        if(!root) 
            return;

        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        return pre;
    }
};