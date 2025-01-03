/*
    Given a binary tree, determine if it is height-balanced

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: true
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
    int height(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        return (abs(lh - rh) <=1 && isBalanced(root->left) && isBalanced(root->right));
    }
};