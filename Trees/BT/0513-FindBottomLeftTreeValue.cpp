/*
    Given the root of a binary tree, return the leftmost value in the last row of the tree.

    Example 1:
    Input: root = [2,1,3]
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return -1;
        
        vector<vector<int>> level;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> arr;

            for(int i=0;i<n;i++) {
                TreeNode* curr = q.front();
                q.pop();

                arr.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            level.push_back(arr);
        }

        return level[level.size()-1][0];
    }
};