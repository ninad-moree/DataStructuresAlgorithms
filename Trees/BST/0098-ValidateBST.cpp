/*
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).
    A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
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
    bool isValid(TreeNode* root, long maxi, long mini) {
        if(!root)
            return true;
        
        if(root->val >= maxi || root->val <= mini)
            return false;
        
        return isValid(root->left, root->val, mini) && isValid(root->right, maxi, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MAX, LLONG_MIN);
    }
};