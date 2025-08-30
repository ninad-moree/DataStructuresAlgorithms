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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        if(!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            if(f != NULL) {
                ans += to_string(f->val);
                ans += ",";
            } else
                ans += "#,";

            if(f != NULL) {
                q.push(f->left);
                q.push(f->right);  
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#")
                f->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                f->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#")
                f->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                f->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};