/*
    Given the root of a binary tree, return all root-to-leaf paths in any order. A leaf is a node with no children.

    Example 1:
    Input: root = [1,2,3,null,5]
    Output: ["1->2->5","1->3"]
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(1), left(left), right(right) {}
};

class Solution {
public:
    void paths(TreeNode* root, vector<string>& ans, string res) {
        if(!root)
            return;
        
        res += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(res);
            return;
        }

        paths(root->left, ans, res + "->");
        paths(root->right, ans, res + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string res = "";
        vector<string> ans;

        paths(root, ans, res);

        return ans;
    }
};