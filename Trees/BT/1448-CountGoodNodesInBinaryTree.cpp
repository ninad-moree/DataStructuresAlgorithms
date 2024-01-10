/*
    Given a binary tree root, a node X in the tree is named good if in the path from root to X there 
    are no nodes with a value greater than X.
    Return the number of good nodes in the binary tree.

    Example 1:
    Input: root = [3,1,4,3,null,1,5]
    Output: 4
    Explanation: Nodes in blue are good.
    Root Node (3) is always a good node.
    Node 4 -> (3,4) is the maximum value in the path starting from the root.
    Node 5 -> (3,4,5) is the maximum value in the path
    Node 3 -> (3,1,3) is the maximum value in the path.
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
    int goodNodes(TreeNode* root) {
        if (!root) 
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val}); 

        int count = 0;

        while (!st.empty()) {
            TreeNode* node = st.top().first;
            int maxSoFar = st.top().second;
            st.pop();

            if (node->val >= maxSoFar) 
                count++;

            if (node->left)
                st.push({node->left, max(maxSoFar, node->left->val)});
            if (node->right) 
                st.push({node->right, max(maxSoFar, node->right->val)});
        }

        return count;
    }
};