/*
    Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in
    the tree are cousins, or false otherwise. Two nodes of a binary tree are cousins if they have the same depth with different parents. Note that in a binary tree, the root 
    node is at the depth 0, and children of each depth k node are at the depth k + 1.

    Example 1:
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q; // node, parent
        q.push({root, NULL});

        while(!q.empty()) {
            int s = q.size();

            TreeNode* parentX = NULL;
            TreeNode* parentY = NULL;

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();

                TreeNode* node = f.first;
                TreeNode* parent = f.second;

                if(node->val == x)
                    parentX = parent;
                if(node->val == y)
                    parentY = parent;

                if(node->left)
                    q.push({node->left, node});
                if(node->right)
                    q.push({node->right, node});
            }

            if(parentX && parentY) // same level and difft parents
                return parentX != parentY;
            if(parentX || parentY) // found only 1 node
                return false;
        }

        return false;
    }
};