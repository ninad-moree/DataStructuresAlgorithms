/*
    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or 
    memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization 
    algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized 
    to the original tree structure.
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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "null,";

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* buildTree(stringstream& ss) {
        string str;
        getline(ss, str, ',');
        if (str == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(str));
        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};