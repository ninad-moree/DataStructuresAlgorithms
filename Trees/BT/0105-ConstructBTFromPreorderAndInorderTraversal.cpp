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
    TreeNode* buildTreePreIn(vector<int>& inorder, int is, int ie, vector<int>& preorder, int ps, int pe, map<int, int>& mp) {
        if(ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int idxRoot = mp[preorder[ps]];
        int numsOnLeft = idxRoot - is;

        root->left = buildTreePreIn(inorder, is, idxRoot - 1, preorder, ps+1, ps + numsOnLeft, mp);
        root->right = buildTreePreIn(inorder, idxRoot + 1, ie, preorder, ps + numsOnLeft + 1, pe, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() != preorder.size())
            return NULL;

        int ino = inorder.size();
        int pre = preorder.size();

        map<int, int> mp;

        for(int i=0; i<ino; i++)
            mp[inorder[i]] = i;

        return buildTreePreIn(inorder, 0, ino -1, preorder, 0, pre - 1, mp);
    }
};