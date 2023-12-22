/*
    Given the root of a binary tree, determine if it is a complete binary tree.
    In a complete binary tree, every level, except possibly the last, is completely filled, 
    and all nodes in the last level are as far left as possible. It can have between 1 and 
    2h nodes inclusive at the last level h.
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
    int count(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 1 + count(root->left) + count(root->right);
        return ans;
    }
    
    bool solve(TreeNode* root, int index, int cnt) {
        if(root == NULL)
            return true;
        
        if(index>=cnt)
            return false;
        else{
            bool left = solve(root->left, 2*index+1, cnt);
            bool right = solve(root->right, 2*index+2, cnt);
            return left && right;
        }
    }
    
    bool isCompleteTree(TreeNode* root) {
        int index=0;
        int cnt = count(root);
        return solve(root, index, cnt);
    }
};