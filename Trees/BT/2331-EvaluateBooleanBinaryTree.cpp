/*
    You are given the root of a full binary tree with the following properties:
    Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
    Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
    The evaluation of a node is as follows:
    If the node is a leaf node, the evaluation is the value of the node, i.e. True or False. Otherwise, evaluate the node's two children and apply 
    the boolean operation of its value with the children's evaluations.
    Return the boolean result of evaluating the root node.

    Example 1:
    Input: root = [2,1,3,null,null,0,1]
    Output: true
    Explanation: The above diagram illustrates the evaluation process.
    The AND node evaluates to False AND True = False.
    The OR node evaluates to True OR False = True.
    The root node evaluates to True, so we return true.
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
        if(root->val == 0 || root->val == 1)
            return root->val == 1;
        else if(root->val == 2) 
            return solve(root->left) || solve(root->right);
        else if(root->val == 3)
            return solve(root->left) && solve(root->right);
        else
            return false;
    }

    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};