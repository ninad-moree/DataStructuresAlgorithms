/*
    Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
    (i.e., from left to right, level by level from leaf to root).

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
        vector<vector<int>> ans;

        if(root == NULL) 
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for(int i=0;i<n;i++) {
                TreeNode* num = q.front();
                q.pop();

                if(num->left != NULL) 
                    q.push(num->left);
                if(num->right != NULL) 
                    q.push(num->right);
                temp.push_back(num->val);
            }
            ans.push_back(temp);
        }

        stack<vector<int>> reverse;
        for(const auto& level : ans)
            reverse.push(level);

        vector<vector<int>> result;
        while(!reverse.empty()) {
            result.push_back(reverse.top());
            reverse.pop();
        }
        return result;
    }
};