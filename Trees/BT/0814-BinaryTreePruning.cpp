/*
    Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed. A subtree of a node node is node plus 
    every node that is a descendant of node.

    Example 1:
    Input: root = [1,null,0,0,1]
    Output: [1,null,0,null,1]
    Explanation:  Only the red nodes satisfy the property "every subtree not containing a 1". The diagram on the right represents the answer.
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
    bool solve(TreeNode* root) {
        if(!root)
            return false;

        bool left = solve(root->left);
        bool right = solve(root->right);

        if(!left)
            root->left = NULL;

        if(!right)
            root->right = NULL;

        return root->val == 1 || left || right;
    }

    TreeNode* pruneTree(TreeNode* root) {
        solve(root);

        if(root && root->val == 0 && !root->left && !root->right)
            return nullptr;

        return root;
    }
};