/*
    You are given the root of a binary tree containing digits from 0 to 9 only.
    Each root-to-leaf path in the tree represents a number.
    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
    Return the total sum of all root-to-leaf numbers. Test cases are generated 
    so that the answer will fit in a 32-bit integer.
    A leaf node is a node with no children.

    Example 1:
    Input: root = [1,2,3]
    Output: 25
    Explanation:
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.
    Therefore, sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;

        int totalSum = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            TreeNode* node = st.top().first;
            int currentSum = st.top().second;
            st.pop();

            if (node->left == nullptr && node->right == nullptr)
                totalSum += currentSum;

            if (node->right) 
                st.push({node->right, currentSum * 10 + node->right->val});
        
            if (node->left) 
                st.push({node->left, currentSum * 10 + node->left->val});
        }

        return totalSum;
    }
};