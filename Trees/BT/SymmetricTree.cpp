/*
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:
    Input: root = [1,2,2,3,4,4,3]
    Output: true
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

    bool check (TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p==NULL && q!=NULL || p!=NULL && q==NULL) 
            return false;
        else {
            bool l = check(p->left, q->right);
            bool r = check(p->right, q->left);
            bool val = p->val == q->val;
            return val && l && r;
        }
    }

    bool isSymmetric(TreeNode* root) {
        bool ans;
        
        if(root->left==NULL && root->right==NULL) {
            ans =  true;
            return ans;
        }
        else if(root->left==NULL && root->right!=NULL) {
            ans = false;
            return ans;
        }
        else if(root->left!=NULL && root->right==NULL) {
            ans = false;
            return ans;
        }
        else if(root->left != NULL && root->right != NULL) {
            TreeNode *p = root->left;
            TreeNode *q = root->right;

            ans = check(p,q);
        }
        return ans;
    }
};