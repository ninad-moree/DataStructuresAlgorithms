/*
    Given the root of a binary tree, invert the tree, and return its root.
    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()) {
            TreeNode *curr = s.top();
            s.pop();

            TreeNode* temp;
            temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if(curr->left!=NULL) 
                s.push(curr->left);
            if(curr->right!=NULL) 
                s.push(curr->right);
        }
        return root;
    }
};