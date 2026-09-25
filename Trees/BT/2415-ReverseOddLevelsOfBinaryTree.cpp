/*
    Given the root of a perfect binary tree, reverse the node values at each odd level of the tree. For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], 
    then it should become [18,29,11,7,4,3,1,2]. Return the root of the reversed tree. A binary tree is perfect if all parent nodes have two children and all leaves are on the 
    same level. The level of a node is the number of edges along the path between it and the root node.

    Example 1:
    Input: root = [2,3,5,8,13,21,34]
    Output: [2,5,3,8,13,21,34]
    Explanation: The tree has only one odd level. The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
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
    void dfs(TreeNode* left, TreeNode* right, int lvl) {
        if(!left || !right)
            return;

        if(lvl % 2 == 0) {
            int val = left->val;
            left->val = right->val;
            right->val = val;
        }

        dfs(left->left, right->right, lvl + 1);
        dfs(left->right, right->left, lvl + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 0);
        return root;
    }
};