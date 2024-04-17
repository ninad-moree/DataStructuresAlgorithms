/*
    You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
    Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root. As a reminder, any shorter prefix 
    of a string is lexicographically smaller. For example, "ab" is lexicographically smaller than "aba".

    Example 1:
    Input: root = [0,1,2,3,4,3,4]
    Output: "dba"
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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string path, string& ans) {
        if (!root) 
            return;
        
        path += char('a' + root->val);
        
        if (!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans) 
                ans = path;
            reverse(path.begin(), path.end());
        }
        
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    
    }
};