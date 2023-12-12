/*
    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the 
    longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;

        return max(left, right);
    }
};