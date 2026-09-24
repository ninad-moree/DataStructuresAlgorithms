/*
    Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path 
    should be returned as a list of the node values, not node references. A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is 
    a node with no children.

    Example 1:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Output: [[5,4,11,2],[5,8,4,5]]
    Explanation: There are two paths whose sum equals targetSum: 5 + 4 + 11 + 2 = 22, 5 + 8 + 4 + 5 = 22
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
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, int sum, vector<int>& res) {
        if(!root)
            return;

        res.push_back(root->val);
        sum += root->val;

        if(!root->left && !root->right) {
            if(sum == targetSum)
                ans.push_back(res);

            res.pop_back();
            return;
        }

        solve(root->left, targetSum, ans, sum, res);
        solve(root->right, targetSum, ans, sum, res);

        res.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(root, targetSum, ans, 0, res);

        return ans;
    }
};