/*
    Given the root of a binary tree, imagine yourself standing on the right side of it, 
    return the values of the nodes you can see ordered from top to bottom.

    Example 1:
    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(1), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;

        if(!root)
            return ans; 

        q.push({root, 0});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            TreeNode* node = f.first;
            int lvl = f.second;

            mp[lvl] = node->val;

            if(node->left)
                q.push({node->left, lvl + 1});
            if(node->right)
                q.push({node->right, lvl + 1});
        }

        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};