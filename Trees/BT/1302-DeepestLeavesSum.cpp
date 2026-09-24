/*
    Given the root of a binary tree, return the sum of values of its deepest leaves.
 
    Example 1:
    Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
    Output: 15
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
    int height(TreeNode* root) {
        if(!root)
            return 0;

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return max(left, right);
    }

    int postorder(TreeNode* root, int lvl, int ht, int& sum) {
        if(!root)
            return sum;

        if(!root->left && !root->right && lvl == ht)
            sum += root->val;

        postorder(root->left, lvl + 1, ht, sum);
        postorder(root->right, lvl + 1, ht, sum);

        return sum;
    }

    int deepestLeavesSum(TreeNode* root) {
        int ht = height(root);
        int sum = 0;
        postorder(root, 1, ht, sum);

        return sum;
    }
};