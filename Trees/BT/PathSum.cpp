/*
    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
    such that adding up all the values along the path equals targetSum.
    A leaf is a node with no children.

    Example 1:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    Output: true
    Explanation: The root-to-leaf path with the target sum is shown.
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
    bool sumNodes (TreeNode *root, int targetSum, int sum) {
        if(root == NULL) 
            return false;
        if(root->left == NULL && root->right == NULL) {
            sum = sum + root->val;
            if(sum==targetSum) 
                return true;
        }
        return sumNodes(root->left, targetSum, sum + root->val) || sumNodes(root->right, targetSum, sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return sumNodes(root,targetSum,sum);
    }
};