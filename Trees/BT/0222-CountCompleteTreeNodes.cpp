/*
    Given the root of a complete binary tree, return the number of the nodes in the tree. According to Wikipedia, every level, except 
    possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It
    can have between 1 and 2h nodes inclusive at the last level h. Design an algorithm that runs in less than O(n) time complexity.

    Example 1
    Input: root = [1,2,3,4,5,6]
    Output: 6
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
    vector<int> ino;
    
    void inorder(TreeNode* root) {
        if(!root) 
            return;
            
        inorder(root->left);
        ino.push_back(root->val);
        inorder(root->right);
    }

    int countNodes(TreeNode* root) {
        inorder(root);
        return ino.size();
    }
};