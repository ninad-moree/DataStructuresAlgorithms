/*
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree 
    without changing its structure.

    Example 1:
    Input: root = [1,3,null,null,2]
    Output: [3,1,null,null,2]
    Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
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
    TreeNode* first, *middle, *last, *prev;

    void inorder(TreeNode* root) {
        if(!root)
            return;

        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)) {
            if(first == NULL) {
                first = prev;
                middle = root;
            } else
                last = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first && last)
            swap(first->val, last->val);
        else if(first && middle)
            swap(first->val, middle->val);
    }
};