/*
    Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree 
    with the preorder traversal way, and return it.
    Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string 
    and the original binary tree.

    Example 1:
    Input: root = [1,2,3,4]
    Output: "1(2(4))(3)"
    Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty 
    parenthesis pairs. And it will be "1(2(4))(3)"
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
    void check(TreeNode* root, string& str) {
        if(root == NULL)
            return;
        
        str += to_string(root->val);

        if(root->left || root->right) {
            str+='(';
            check(root->left, str);
            str+=')';
        }
        if(root->right) {
            str+='(';
            check(root->right, str);
            str+=')';
        }
    }

    string tree2str(TreeNode* root) {
        string str = "";
        check(root, str);
        return str;
    }
};