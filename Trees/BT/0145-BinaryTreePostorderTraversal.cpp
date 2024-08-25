/*
    Given the root of a binary tree, return the postorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [3,2,1]
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
    vector<int> pos;

    void postorder(TreeNode* root) {
        if(!root)
            return;

        postorder(root->left);
        postorder(root->right);
        pos.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return pos;
    }
};