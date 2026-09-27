/*
    Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0. A 
    grandparent of a node is the parent of its parent if it exists.

    Example 1:
    Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
    Output: 18
    Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
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
    void findParent(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& par) {
        if(!root)
            return;
        
        if(prev != NULL)
            par[root] = prev;

        findParent(root->left, root, par);
        findParent(root->right, root, par);
    }

    void inorder(TreeNode* root, int& sum, unordered_map<TreeNode*, TreeNode*>& par) {
        if(!root)
            return;

        inorder(root->left, sum, par);

        TreeNode* parent = par[root];

        if(parent != NULL) {
            TreeNode* grandParent = par[parent];

            if(grandParent != NULL && grandParent->val % 2 == 0) 
                sum += root->val;
        }

        inorder(root->right, sum, par);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;

        unordered_map<TreeNode*, TreeNode*> par; // node -> par
        par[root] = NULL;

        findParent(root, NULL, par);

        int ans = 0;

        inorder(root, ans, par);

        return ans;
    }

/* ====================================================================== SECOND METHOD - DIRECT DFS ======================================================================= */ 
    vector <int> res;

    void solve(TreeNode* root) {
        if (root == NULL) 
            return;

        if (root -> val % 2 == 0) {
            if (root -> left and root -> left -> left) 
                res.push_back(root -> left -> left -> val);
            if (root -> left and root -> left -> right) 
                res.push_back(root -> left -> right -> val);
            if (root -> right and root -> right -> left) 
                res.push_back(root -> right -> left -> val);
            if (root -> right and root -> right -> right) 
                res.push_back(root -> right -> right -> val);
        }

        solve(root -> left);
        solve(root -> right);

        return;
    }

    int sumEvenGrandparent2(TreeNode* root) {
        solve(root);
        int tot = accumulate(res.begin(), res.end(), 0);
        return tot;
    }
};