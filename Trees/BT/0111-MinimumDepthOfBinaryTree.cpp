/*
    Given a binary tree, find its minimum depth.
    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    Note: A leaf is a node with no children.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                TreeNode* curr = q.front();
                q.pop();

                if(!curr->left && !curr->right)
                    return depth;
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            depth++;
        }

        return depth;
    }
};