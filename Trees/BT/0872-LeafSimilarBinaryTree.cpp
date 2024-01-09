/*
    Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
    Two binary trees are considered leaf-similar if their leaf value sequence is the same.
    Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    void inorder(TreeNode* root, vector<int>& leafs) {
        if (root == NULL)
            return;

        inorder(root->left, leafs);

        if (root->left == NULL && root->right == NULL)
            leafs.push_back(root->val);

        inorder(root->right, leafs);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;

        inorder(root1, l1);
        inorder(root2, l2);

        if(l1.size() != l2.size())
            return false;

        for(int i=0;i<l1.size();i++) {
            if(l1[i] != l2[i])
                return false;
        }

        return true;
    }
};