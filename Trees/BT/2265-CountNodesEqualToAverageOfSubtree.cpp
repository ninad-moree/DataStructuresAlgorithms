/*
    Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree. Note: The average of n elements
    is the sum of the n elements divided by n and rounded down to the nearest integer. A subtree of root is a tree consisting of root and all of its descendants.

    Example 1:
    Input: root = [4,8,5,0,1,null,6]
    Output: 5
    Explanation:  For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
    For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5. For the node with value 0: The average of its subtree is 0 / 1 = 0.
    For the node with value 1: The average of its subtree is 1 / 1 = 1. For the node with value 6: The average of its subtree is 6 / 1 = 6.
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
    int cnt = 0;

    // returns {sum, node}
    pair<int, int> calculateSubtreeValues(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        auto leftSubtree = calculateSubtreeValues(root->left);
        auto rightSubtree = calculateSubtreeValues(root->right);

        int sum = leftSubtree.first + rightSubtree.first + root->val;
        int node = leftSubtree.second + rightSubtree.second + 1;

        if (node != 0 && sum / node == root->val)
            cnt++; 

        return {sum, node};
    }

    int averageOfSubtree(TreeNode* root) {
        calculateSubtreeValues(root); 
        
        return cnt; 
    }
};