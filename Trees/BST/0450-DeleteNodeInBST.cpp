/*
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference 
    (possibly updated) of the BST. Basically, the deletion can be divided into two stages: Search for a node to remove.
    If the node is found, delete the node.
    
    Example 1:
    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
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
    TreeNode* findLastRight(TreeNode* root) {
        if(!root->right)
            return root;

        return findLastRight(root->right);
    }

    TreeNode* deleteAndRearrange(TreeNode* root) {
        if(!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;

        if(root->val == key) 
            return deleteAndRearrange(root);

        TreeNode* node = root;

        while(root != NULL) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    root->left = deleteAndRearrange(root->left);
                    break;
                } else
                    root = root->left;
            } else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = deleteAndRearrange(root->right);
                    break;
                } else
                    root = root->right;
            }
        }

        return node;
    }
};