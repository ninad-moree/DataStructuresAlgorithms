/*
    Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
    Note that the root node is at depth 1.
    The adding rule is:
    Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left 
    subtree root and right subtree root.
    cur's original left subtree should be the left subtree of the new left subtree root.
    cur's original right subtree should be the right subtree of the new right subtree root.
    If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original 
    tree, and the original tree is the new root's left subtree.
    
    Example 1:
    Input: root = [4,2,6,3,1,5], val = 1, depth = 2
    Output: [4,1,1,2,null,null,6,3,1,5]
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
    void addHelper(TreeNode* node, int val, int depth, int currentDepth) {
        if (!node) 
            return;
        
        if (currentDepth == depth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            newLeft->left = node->left;
            newRight->right = node->right;
            node->left = newLeft;
            node->right = newRight;

            return;
        }
        
        addHelper(node->left, val, depth, currentDepth + 1);
        addHelper(node->right, val, depth, currentDepth + 1);
    }


    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        addHelper(root, val, depth, 1);
        return root;
    }
};