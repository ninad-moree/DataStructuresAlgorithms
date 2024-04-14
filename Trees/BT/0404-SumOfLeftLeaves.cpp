/*
    Given the root of a binary tree, return the sum of all left leaves.
    A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) 
            return 0;

        int sum = 0;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
            
        sum += sumOfLeftLeaves(root->left); 
        sum += sumOfLeftLeaves(root->right); 

        return sum;
    }
};