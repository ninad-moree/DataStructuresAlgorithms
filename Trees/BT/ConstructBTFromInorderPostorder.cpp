/*
    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
    postorder is the postorder traversal of the same tree, construct and return the binary tree.

    Example 1:
    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]
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
    map<int, int> createMapping(vector<int>& inorder) {
        map<int, int> nodeToIndex;
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
        return nodeToIndex;
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& posIndex, int inStart, int inEnd, map<int, int>& nodeToIndex) {
        if (posIndex < 0 || inStart > inEnd) {
            return nullptr;
        }

        int element = postorder[posIndex];
        posIndex--;
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->right = solve(postorder, inorder, posIndex, position + 1, inEnd, nodeToIndex);
        root->left = solve(postorder, inorder, posIndex, inStart, position - 1, nodeToIndex);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = inorder.size() -1;
        map<int, int> nodeToIndex = createMapping(inorder);

        return solve(postorder, inorder, postorderIndex, 0, inorder.size() - 1, nodeToIndex);
    }
};