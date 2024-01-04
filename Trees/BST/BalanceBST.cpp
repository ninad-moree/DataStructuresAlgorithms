/*
    Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
    If there is more than one answer, return any of them.
    A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
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
    void inorder(TreeNode* root, vector<int> &inn) {
        if(root == NULL)
            return;
            
        inorder(root->left, inn);
        inn.push_back(root->val);
        inorder(root->right, inn);
    }


    TreeNode* inordertToBST(int s, int e, vector<int>& arr) {
        if(s>e)
            return NULL;
        
        int mid = (s+e)/2;

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = inordertToBST(s, mid-1, arr);
        root->right = inordertToBST(mid+1, e, arr);

        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root , arr);

        return inordertToBST(0, arr.size()-1, arr);
    }
};