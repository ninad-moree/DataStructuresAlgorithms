/*
    Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST). Assume a BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key. The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    
    Example 1:
    Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    Output: 20
    Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
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


class NodeVal {
public:
    int minNode, maxNode, sum;

    NodeVal(int mini, int maxi, int s) {
        minNode = mini;
        maxNode =  maxi;
        sum = s;
    }
};

class Solution {
public:
    int maxSum = 0; // as if the sum is  negative return 0

    NodeVal solve(TreeNode* root) {
        if(!root)
            // this implies Node is always a valid BST as right.minNode = INT_Max and left.maxNode = INT_MIN
            // therefor=> left.maxNode < node < right.minNode ==> INT_MIN < node < INT_MAX ==> always true ==> valid BST
            return NodeVal(INT_MAX, INT_MIN, 0); 

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Tree is a valid BST
        // compare the root val with the largest value from left and smallest value from right
        if(left.maxNode < root->val && right.minNode > root->val) { 
            int mini = min(root->val, left.minNode);  // pass the min value of the left subtree to the parent node
            int maxi = max(root->val, right.maxNode); // pass the max value of the right subtree to the parent node
            int sum = left.sum + right.sum + root->val;

            maxSum = max(maxSum, sum);

            return NodeVal(mini, maxi, sum);
        }

        // Not a valid BST: therefore pass mini = INT_MIN and maxi = INT_MAX
        // therefore=> left.maxNode < node < right.minNode ==> INT_MAX < node < INT_MIN ==> never true ==> not valid BST
        return NodeVal(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

    int maxSumBST(TreeNode* root) {
        solve(root);

        return maxSum;
    }
};