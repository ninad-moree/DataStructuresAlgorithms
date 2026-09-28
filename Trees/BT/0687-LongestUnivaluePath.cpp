/*
    Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root. The 
    length of the path between two nodes is represented by the number of edges between them.

    Example 1:
    Input: root = [5,4,5,1,1,null,5]
    Output: 2
    Explanation: The shown image shows that the longest path of the same value (i.e. 5).
*/

#include <bits/stdc++.h>
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
    int dfs(TreeNode* root, int parent, int& ans) {
        if(!root)
            return 0;

        int left = dfs(root->left, root->val, ans);
        int right = dfs(root->right, root->val, ans);

        ans = max(ans, left + right);

        return root->val == parent ? max(left, right) + 1 : 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(root, -1, ans);

        return ans;
    }
};