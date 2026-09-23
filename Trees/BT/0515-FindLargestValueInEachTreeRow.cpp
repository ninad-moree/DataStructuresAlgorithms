/*
    Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

    Example 1:
    Input: root = [1,3,2,5,3,null,9]
    Output: [1,3,9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            int maxi = INT_MIN;

            while(s--) {
                TreeNode* n = q.front();
                q.pop();

                maxi = max(maxi, n->val);

                if(n->left)
                    q.push(n->left);

                if(n->right)
                    q.push(n->right);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};