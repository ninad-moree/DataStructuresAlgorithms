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
    void solve(TreeNode* root, vector<int>& ans, int lvl) {
        if(root == NULL) 
            return;

        if(lvl == ans.size())
            ans.push_back(root->val);

        solve(root->right, ans, lvl+1);
        solve(root->left, ans, lvl+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};