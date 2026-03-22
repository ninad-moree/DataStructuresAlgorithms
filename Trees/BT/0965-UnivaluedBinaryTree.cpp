/*
    A binary tree is uni-valued if every node in the tree has the same value. Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

    Example 1:
    Input: root = [1,1,1,1,1,null,1]
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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return 0;

        int val = root->val;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();

                if(f->val != val) 
                    return false;

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);   
            }
        }

        return true;
    }
};