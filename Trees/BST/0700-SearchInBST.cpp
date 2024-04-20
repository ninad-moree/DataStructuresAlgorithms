/*
    You are given the root of a binary search tree (BST) and an integer val. Find the node in the BST that the node's value equals val and 
    return the subtree rooted with that node. If such a node does not exist, return null.

    Example 1:
    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        
        TreeNode* temp = root;

        while(temp != NULL) {
            if(temp->val > val) 
                temp = temp->left;
            else if(temp->val < val)
                temp = temp->right;
            else
                break;
        }

        return temp;
    }
};