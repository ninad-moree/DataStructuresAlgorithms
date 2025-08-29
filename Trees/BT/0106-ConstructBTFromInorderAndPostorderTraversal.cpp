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
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& mp) {
        if(ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int idxRoot = mp[postorder[pe]];
        int numsOnLeft = idxRoot - is;

        root->left = buildTreePostIn(inorder, is, idxRoot - 1, postorder, ps, ps + numsOnLeft -1, mp);
        root->right = buildTreePostIn(inorder, idxRoot + 1, ie, postorder, ps + numsOnLeft, pe - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;

        int ino = inorder.size();
        int post = postorder.size();

        map<int, int> mp;

        for(int i=0; i<ino; i++)
            mp[inorder[i]] = i;

        return buildTreePostIn(inorder, 0, ino -1, postorder, 0, post - 1, mp);
    }
};