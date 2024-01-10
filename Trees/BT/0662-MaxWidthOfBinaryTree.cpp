/*
    Given the root of a binary tree, return the maximum width of the given tree.
    The maximum width of a tree is the maximum width among all levels.
    The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
    where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that 
    level are also counted into the length calculation.
    It is guaranteed that the answer will in the range of a 32-bit signed integer.

    Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: 4
    Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
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

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) 
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q; 
        q.push({root, 1});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second, right = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                right = q.front().second;
                q.pop();

                if (node->left) 
                    q.push({node->left, 2 * right});
                if (node->right) 
                    q.push({node->right, 2 * right + 1});
            }

            maxWidth = max(maxWidth, static_cast<int>(right - left + 1));
        }

        return maxWidth;
    }
};