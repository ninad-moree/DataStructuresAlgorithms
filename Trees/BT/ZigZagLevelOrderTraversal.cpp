/*
    Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
    (i.e., from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        bool reverse = false;

        while (!q.empty()){
            int size = q.size();
            vector<int> lev;
            for(int i=0;i<size;i++) {
                TreeNode* t = q.front();
                q.pop();

                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);

                if(reverse)
                    lev.insert(lev.begin(), t->val);
                else
                    lev.push_back(t->val);
            }
            ans.push_back(lev);
            reverse = !reverse;
        }
        return ans;
    }
};