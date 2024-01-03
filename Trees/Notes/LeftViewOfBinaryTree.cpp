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

void solve(TreeNode* root, vector<int>& ans, int lvl) {
    if(lvl == ans.size())
        ans.push_back(root->val);
    
    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
}

vector<int> leftView(TreeNode* root) {
    if(root == NULL)
        return {};
    
    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}