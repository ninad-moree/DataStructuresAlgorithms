/*
    Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST 
    such that their sum is equal to k, or false otherwise.

    Example 1:
    Input: root = [5,3,6,2,4,null,7], k = 9
    Output: true
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
    void inorder(TreeNode* root, vector<int> &inn) {
        if(root == NULL)
            return;

        inorder(root->left, inn);
        inn.push_back(root->val);
        inorder(root->right, inn);
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int> ino;
        inorder(root, ino);

        int i=0;
        int j=ino.size()-1;

        while(i<j) {
            int sum = ino[i] + ino[j];
            
            if(sum == k)
                return true;
            else if (sum > k)
                j--;
            else
                i++;
        }
        return false;
    }
};