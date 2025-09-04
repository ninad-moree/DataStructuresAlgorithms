/*
    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the 
    insertion. It is guaranteed that the new value does not exist in the original BST. Notice that there may exist multiple valid ways for the 
    insertion, as long as the tree remains a BST after insertion. You can return any of them.

    Example 1:
    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);

        if(!root) {
            root = node;
            return root;
        }

        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while(curr) {
            if(curr->val < val) {
                prev = curr;
                curr =  curr->right;
            } else {
                prev = curr;
                curr = curr->left;
            }
        }

        if(prev->val > val)
            prev->left = node;
        else
            prev->right = node;

        return root;
    }
};