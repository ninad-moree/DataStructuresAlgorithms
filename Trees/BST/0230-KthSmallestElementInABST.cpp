/*
    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

    Example 1:
    Input: root = [3,1,4,null,2], k = 1
    Output: 1
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
    void inorder(TreeNode* root, int& cnt, int k, int& ans) {
        if(!root)
            return;
        
        inorder(root->left, cnt, k, ans);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, cnt, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;

        inorder(root, cnt, k, ans);

        return ans;
    }
};