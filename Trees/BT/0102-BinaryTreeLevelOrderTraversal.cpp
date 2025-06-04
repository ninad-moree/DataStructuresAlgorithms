/*
    Given the root of a binary tree, return the level order traversal of its nodes' values. 
    (i.e., from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> lvl;

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();

                lvl.push_back(f->val);

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }

            ans.push_back(lvl);
        }

        return ans;
    }
};