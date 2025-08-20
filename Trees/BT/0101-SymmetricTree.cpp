/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(1), left(left), right(right) {}
};

class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right) {
        if(left == NULL || right == NULL)
            return left == right;

        if(left->val != right->val)
            return false;
        
        return solve(left->left, right->right) && solve(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return root == NULL || solve(root->left, root->right);
    }
};