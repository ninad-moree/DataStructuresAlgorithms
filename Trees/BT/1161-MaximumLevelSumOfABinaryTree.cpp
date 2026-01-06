/*
    Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on. Return the smallest level x such that the sum of all the values of 
    nodes at level x is maximal.

    Example 1:
    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation: 
    Level 1 sum = 1. Level 2 sum = 7 + 0 = 7. Level 3 sum = 7 + -8 = -1. So we return the level with the maximum sum which is level 2.
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
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return INT_MIN;

        int ans = INT_MAX;
        int sum = INT_MIN;
        int lvl = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            int currSum = 0;

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();

                currSum += f->val;

                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }

            if(currSum > sum) {
                ans = lvl;
                sum = currSum;
            }

            lvl++;
        }

        return ans;
    }
};