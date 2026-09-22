/*
    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root. Besides the root, each house has one and only one 
    parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses
    were broken into on the same night. Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

    Example 1:
    Input: root = [3,2,3,null,3,null,1]
    Output: 7
    Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
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
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if(!root)
            return 0;

        if(dp.count(root))
            return dp[root];

        // Don't rob current house
        int notTake = solve(root->left, dp) + solve(root->right, dp);

        // Rob current house
        int take = root->val;

        if(root->left) {
            take += solve(root->left->left, dp);
            take += solve(root->left->right, dp);
        }

        if(root->right) {
            take += solve(root->right->left, dp);
            take += solve(root->right->right, dp);
        }

        return dp[root] = max(take, notTake);
    }

    int rob(TreeNode* root) {
        // The maximum amount of money we can rob from the subtree rooted at node,
        unordered_map<TreeNode*, int> dp;
        
        return solve(root, dp);
    }
};