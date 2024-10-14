/*
    You are given the root of a binary tree and an integer k. Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if
    it doesn't exist. A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
    
    Example 1:
    Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
    Output: 3
    Explanation:
    The roots of the perfect binary subtrees are highlighted in black. Their sizes, in decreasing order are [3, 3, 1, 1, 1, 1, 1, 1].
    The 2nd largest size is 3.
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
    pair<bool, int> solve(TreeNode* root, vector<int>& ans) {
        if(!root)
            return {true, 0};
        
        pair<bool, int> left = solve(root->left, ans);
        pair<bool, int> right = solve(root->right, ans);

        if(left.first && right.first && left.second == right.second) {
            int size = left.second + right.second + 1;
            ans.push_back(size);
            return {true, size};
        }

        return {false, 0};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        solve(root, ans);

        sort(ans.rbegin(), ans.rend());

        if(ans.size() >= k)
            return ans[k-1];
        return -1;
    }
};