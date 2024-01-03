/*
    Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values 
    along the path equals targetSum.
    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from 
    parent nodes to child nodes).

    Example 1:
    Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    Output: 3
    Explanation: The paths that sum to 8 are shown.
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
    void solve(TreeNode* root, int k, int& cnt, vector<int> path) {
        if(root == NULL)
            return;
        
        path.push_back(root->val);

        solve(root->left, k, cnt, path);
        solve(root->right, k, cnt, path);

        long long int sum = 0;
        for(int i = path.size()-1; i>=0; i--) {
            sum += path[i];
            if(sum == k)
                cnt++;
        }

        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int cnt = 0;
        solve(root, targetSum, cnt, path);
        return cnt;
    }
};