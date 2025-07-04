/*
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [1,3,2]
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
    void inorder(TreeNode* root, vector<int>& ino) {
        if(!root)
            return;

        inorder(root->left, ino);
        ino.push_back(root->val);
        inorder(root->right, ino);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ino;
        inorder(root, ino);
        return ino;    
    }
};