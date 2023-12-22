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
    void inorder(TreeNode* root, int& count) {
        if (root == NULL)
            return;

        inorder(root->left, count);
        if (root->left == NULL && root->right == NULL)
            count++;
        inorder(root->right, count);
    }
    int countLeaves(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        int count = 0;
        inorder(root, count);
        return count;
    }
};