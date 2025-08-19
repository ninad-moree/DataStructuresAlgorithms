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
        queue<TreeNode*> q;
        bool leftToRight = true;

        if(!root)
            return ans;

        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> lvl;

            while(s > 0) {
                auto f  = q.front();
                q.pop();
                lvl.push_back(f->val);

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);

                s--;
            }

            if(!leftToRight) {
                reverse(lvl.begin(), lvl.end());
                ans.push_back(lvl);
            } else
                ans.push_back(lvl);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};