/*
    Given the root of a Binary Search Tree (BST), return the minimum absolute difference between 
    the values of any two different nodes in the tree.
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
    vector<int> inorder(TreeNode* root) {
        vector<int> in;
        inorderTraversal(root, in);
        return in;
    }

    void inorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == NULL)
            return;

        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> in = inorder(root);
        int mindiff = INT_MAX;

        for(int i=0;i<in.size()-1;i++) {
            mindiff = min(mindiff, abs(in[i+1] - in[i]));
        }

        return mindiff;
    }
};