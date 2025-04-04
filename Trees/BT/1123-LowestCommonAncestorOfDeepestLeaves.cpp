/*
    Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
    Recall that:
    The node of a binary tree is a leaf if and only if it has no children The depth of the root of the tree is 0. if the depth of a node is d, the depth 
    of each of its children is d + 1. The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is 
    in the subtree with root A.
    
    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2, colored in yellow in the diagram. The nodes coloured in blue are the deepest leaf-nodes of the tree.
    Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
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
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if(!root)
            return {root, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if(left.second > right.second)
            return {left.first, left.second + 1};
        
        if(left.second < right.second)
            return {right.first, right.second + 1};

        return {root, left.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};