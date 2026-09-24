/*
    Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order. The subtree sum of 
    a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

    Example 1:
    Input: root = [5,2,-3]
    Output: [2,-3,4]
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
    int solve(TreeNode* root, int sum, unordered_map<int, int>& mp) {
        if(!root)
            return 0;

        int left = solve(root->left, sum, mp);
        int right = solve(root->right, sum, mp);

        sum += root->val + left + right;
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> mp;

        solve(root, 0, mp);

        int maxFreq = 0;

        for(auto i : mp)
            maxFreq = max(maxFreq, i.second);

        for(auto i : mp) {
            if(i.second == maxFreq)
                ans.push_back(i.first);
        }

        return ans;
    }
};