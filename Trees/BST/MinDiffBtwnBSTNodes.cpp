/*
    Given the root of a Binary Search Tree (BST), return the minimum difference between 
    the values of any two different nodes in the tree.

    Example 1:
    Input: root = [4,2,6,1,3]
    Output: 1
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
    void inOrder(TreeNode* root, int& prev_val, int& min_diff) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left, prev_val, min_diff);

        if (prev_val != -1) 
            min_diff = min(min_diff, root->val - prev_val);
        
        prev_val = root->val;

        inOrder(root->right, prev_val, min_diff);
    }

    int minDiffInBST(TreeNode* root) {
        int prev_val = -1; 
        int min_diff = INT_MAX; 

        inOrder(root, prev_val, min_diff);

        return min_diff;
    }
};