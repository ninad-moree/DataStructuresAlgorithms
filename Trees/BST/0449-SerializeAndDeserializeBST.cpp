/*
    Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network 
    connection link to be reconstructed later in the same or another computer environment. Design an algorithm to serialize and deserialize a binary search tree. There is no 
    restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can
    be deserialized to the original tree structure. The encoded string should be as compact as possible.

    Example 1:
    Input: root = [2,1,3]
    Output: [2,1,3]
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string& ans) {
        if(!root)
            return;

        ans += to_string(root->val);
        ans += "-";

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }

    TreeNode* build(string& preorder, int& idx, int upperBound) {
        if(idx >= preorder.size())
            return NULL;

        int start = idx;

        string s = "";
        while(idx < preorder.size() && preorder[idx] != '-') {
            s += preorder[idx];
            idx++;
        }

        if(s == "")
            return NULL;

        int val = stoi(s);

        if(val > upperBound) {
            idx = start;
            return NULL;
        }

        idx++;

        TreeNode* root = new TreeNode(val);

        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, upperBound);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return build(data, idx, INT_MAX);
    }
};
