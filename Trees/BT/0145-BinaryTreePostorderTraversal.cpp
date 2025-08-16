/*
    Given the root of a binary tree, return the postorder traversal of its nodes' values.

    Example 1:
    Input: root = [1,null,2,3]
    Output: [3,2,1]
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
    void postorder(TreeNode* root, vector<int>& pos) {
        if(!root)
            return;

        postorder(root->left, pos);
        postorder(root->right, pos);
        pos.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pos;
        postorder(root, pos);
        return pos;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st1, st2;

        if(!root)
            return ans;

        st1.push(root);

        while(!st1.empty()) {
            auto node = st1.top();
            st1.pop();

            st2.push(node);

            if(node->left != NULL)
                st1.push(node->left);
            if(node->right != NULL)
                st1.push(node->right);
        }

        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};