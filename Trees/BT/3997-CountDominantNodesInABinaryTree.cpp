/*
    You are given the root of a complete binary tree. A node x is called dominant if its value is equal to the maximum value among all nodes in the subtree rooted at x.
    Return the number of dominant nodes in the tree.

    Example 1:
    Input: root = [5,3,8,2,4,7,1]
    Output: 5
    Explanation: The leaf nodes with values 2, 4, 7, and 1 are dominant. The node with value 8 is dominant because its value is the maximum value in its subtree [8, 7, 1].
    Thus, the answer is 5.
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
    int solve(TreeNode* root, int& ans) {
        if(!root)
            return INT_MIN;
        
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        if(root->val >= max(left, right))
            ans++;

        return max(root->val, max(left, right));
    }

    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};