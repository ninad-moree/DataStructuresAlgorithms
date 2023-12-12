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

class Solution{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> lev;
            for(int i=0;i<n;i++) {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
                lev.push_back(temp->val);
            }
            ans.push_back(lev);
        }

        return ans;
    }
};