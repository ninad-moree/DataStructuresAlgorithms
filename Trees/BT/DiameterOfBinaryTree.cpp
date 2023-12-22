/*
    Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two 
    nodes in a tree. This path may or may not pass through the root.
    The length of a path between two nodes is represented by the number of edges between them.

    Example 1:
    Input: root = [1,2,3,4,5]
    Output: 3
    Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
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
    pair<int, int> fastDiameter(TreeNode* root) {
        if(root == NULL)
            return {0,0};
        
        pair<int, int> left = fastDiameter(root->left);
        pair<int, int> right = fastDiameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return fastDiameter(root).first -1;
    }
};