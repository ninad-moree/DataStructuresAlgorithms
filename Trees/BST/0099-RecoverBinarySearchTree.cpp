/*
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree 
    without changing its structure.

    Example 1:
    Input: root = [1,3,null,null,2]
    Output: [3,1,null,null,2]
    Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
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

    TreeNode* searchTree(TreeNode* root, int target) {
        if(!root)
            return nullptr;

        if(root->val == target)
            return root;

        TreeNode* left = searchTree(root->left, target);
        if(left)
            return left;
        return searchTree(root->right, target);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        vector<int> corrIno = ino;
        sort(corrIno.begin(), corrIno.end());

        int first = INT_MIN, second = INT_MIN;

        for(int i=0; i<ino.size(); i++) {
            if(ino[i] != corrIno[i]) {
                if (first == INT_MIN)
                    first = ino[i];
                else {
                    second = ino[i];
                    break;
                }
            }
        }

        TreeNode* f = searchTree(root, first);
        TreeNode* s = searchTree(root, second);

        swap(f->val, s->val);
    }
};