/*
    Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, 
    & right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates.) Left boundary is defined as the path from
    root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or 
    right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not 
    applies to any subtrees. The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if 
    exists. If not, travel to the right subtree. Repeat until you reach a leaf node.The right-most node is also defined by the same way with left &
    right exchanged.
    Example 1
    Input:
    1
    \
        2
    / \
    3   4
    Ouput: [1, 3, 4, 2]
    Explanation:
    The root doesn't have left subtree, so the root itself is left boundary. The leaves are node 3 & 4. The right boundary are node 1,2,4. Note the 
    anti-clockwise direction means you should output reversed right boundary. So order them in anti-clockwise without duplicates & we have [1,3,4,2].
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
    bool isLeaf(TreeNode* node) {
        if(node->left == NULL && node->right == NULL)
            return true;
        return false;
    }

    void addLeftNodes(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while(curr) {
            if(!isLeaf(curr))
                res.push_back(curr->val);
            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRightNodes(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> vec;

        while (curr) {
            if(!isLeaf(curr))
                vec.push_back(curr->val);
            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        for(int i=vec.size()-1; i >=0; i--)
            res.push_back(vec[i]);
    }

    void addLeaves(TreeNode* root, vector<int>& res) {
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }

        if(root->left)
            addLeaves(root->left, res);
        if(root->right)
            addLeaves(root->right, res);
        
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;

        if(!root)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);
        
        addLeftNodes(root, ans);
        addLeaves(root, ans);
        addRightNodes(root, ans);

        return ans;
    }
};