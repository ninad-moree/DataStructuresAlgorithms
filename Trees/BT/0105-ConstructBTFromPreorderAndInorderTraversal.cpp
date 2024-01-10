/*
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary 
    tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    map<int, int> createMapping(vector<int>& inorder) {
        map<int, int> nodeToIndex;

        for (int i = 0; i < inorder.size(); i++) 
            nodeToIndex[inorder[i]] = i;

        return nodeToIndex;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd, map<int, int>& nodeToIndex) {
        if (preIndex >= preorder.size() || inStart > inEnd) 
            return nullptr;

        int element = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->left = solve(preorder, inorder, preIndex, inStart, position - 1, nodeToIndex);
        root->right = solve(preorder, inorder, preIndex, position + 1, inEnd, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        map<int, int> nodeToIndex = createMapping(inorder);

        return solve(preorder, inorder, preorderIndex, 0, inorder.size() - 1, nodeToIndex);
    }
};