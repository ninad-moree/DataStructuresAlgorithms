/*
    Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

    Example 1:
    Input: n = 3
    Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
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
    vector<TreeNode*> solve(int start, int end, map<pair<int, int>, vector<TreeNode*>>& dp) {
        vector<TreeNode*> ans;

        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }

        if(dp.find({start, end}) != dp.end())
            return dp[{start, end}];

        for(int i=start; i<=end; i++) {
            vector<TreeNode*> left = solve(start, i-1, dp);
            vector<TreeNode*> right = solve(i+1, end, dp);

            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i, l, r);
                    ans.push_back(root);
                }
            }
        }

        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;

        return solve(1, n, dp);
    }
};