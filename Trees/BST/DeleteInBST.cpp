/*
    Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
    Return the root node reference (possibly updated) of the BST.
    Basically, the deletion can be divided into two stages:
    Search for a node to remove.
    If the node is found, delete the node.
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
    TreeNode* minVal(TreeNode* root) {
        TreeNode* temp = root;
        while(temp->left != NULL) 
            temp = temp->left;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(root->val == key) {
            //0 child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            //1 child
            if(root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if(root->left != NULL && root->right != NULL) {
                int mini = minVal(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right, mini);
                return root;
            }
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else {
            root->right = deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};