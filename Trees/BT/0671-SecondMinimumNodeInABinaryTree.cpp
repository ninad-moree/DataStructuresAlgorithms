/*
    Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two 
    sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.
    Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree. If no such second minimum value exists, 
    output -1 instead.

    Example 1:
    Input: root = [2,2,5,null,null,5,7]
    Output: 5
    Explanation: The smallest value is 2, the second smallest value is 5.
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
    void inorder(TreeNode* root, long long& firstMin, long long& secondMin) {
        if(!root)
            return;

        inorder(root->left, firstMin, secondMin);

        if(root->val < firstMin) {
            secondMin = firstMin;
            firstMin = root->val;
        } else if(root->val != firstMin && root->val < secondMin)
            secondMin = root->val;

        inorder(root->right, firstMin, secondMin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long firstMin = LLONG_MAX;
        long long secondMin = LLONG_MAX;

        inorder(root, firstMin, secondMin);

        return secondMin == LLONG_MAX ? -1 : (int)secondMin;
    }
};