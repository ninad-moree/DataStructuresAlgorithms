/*
    Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[15,7],[9,20],[3]]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
            
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> lvl;

            while(s--) {
                auto node = q.front();
                q.pop();

                lvl.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            ans.push_back(lvl);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};