/*
    Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized. Return the 
    maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    Note that you need to maximize the answer before taking the mod and not after taking it.

    Example 1:
    Input: root = [1,2,3,4,5,6]
    Output: 110
    Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
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
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    void dfsAll(TreeNode* root) {
        if(!root)
            return;

        totalSum += root->val;

        dfsAll(root->left);
        dfsAll(root->right);
    }

    long long dfsSubTree(TreeNode* root) {
        if(!root)
            return 0;

        long long leftSum = dfsSubTree(root->left);
        long long rightSum = dfsSubTree(root->right);

        long long currSum = leftSum + rightSum + root->val;

        long long prod = currSum * (totalSum - currSum);
        maxProd = max(maxProd, prod);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        dfsAll(root);
        dfsSubTree(root);

        return maxProd % MOD;
    }
};