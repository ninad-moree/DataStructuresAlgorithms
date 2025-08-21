/*
    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
    two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a 
    node to be a descendant of itself).”

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.
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
    bool pathToNode(TreeNode* root, vector<TreeNode*>& ans, int node) {
        if(!root)
            return false;

        ans.push_back(root);

        if(root->val == node)
            return true;

        if(pathToNode(root->left, ans, node) || pathToNode(root->right, ans, node))
            return true;

        ans.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;

        pathToNode(root, p1, p->val);
        pathToNode(root, p2, q->val);

        int i = 0, j = 0;

        TreeNode* ans;

        while(i < p1.size() && j < p2.size()) {
            TreeNode* n1 = p1[i];
            TreeNode* n2 = p2[j];

            if(n1->val == n2->val) {
                ans = n1;
                i++;
                j++;
            } else 
                break;
        }

        return ans;
    }
};