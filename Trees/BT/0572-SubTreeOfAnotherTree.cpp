/*
    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same 
    structure and node values of subRoot and false otherwise.
    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
    The tree tree could also be considered as a subtree of itself.

    Example 1:
    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    Output: true
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
    bool checkNode(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        
        if( (p==NULL && q!=NULL) || (p!=NULL && q==NULL) )
            return false;

        bool leftTree = checkNode(p->left, q->left);
        bool rightTree = checkNode(p->right, q->right);

        bool val = p->val == q->val;

        if(leftTree && rightTree && val)
            return true;
        else 
            return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
        return true;
    
        if (root == nullptr)
            return false; 
        
        if (checkNode(root, subRoot))
            return true; 
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};