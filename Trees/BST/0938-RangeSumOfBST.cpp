/*
    Given the root node of a binary search tree and two integers low and high, return the sum of values 
    of all nodes with a value in the inclusive range [low, high].

    Example 1:
    Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
    Output: 32
    Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), height(1), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ino) {
        if(!root)
            return;
        
        inorder(root->left, ino);
        ino.push_back(root->val);
        inorder(root->right, ino);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ino;

        inorder(root, ino);

        int i = 0;
        int j = 0;

        for(int k=0;k<ino.size();k++) {
            if(ino[k]==low)
                i = k;
            if(ino[k]==high)
                j = k;
        }

        int ans = 0;
        for(int l=i;l<=j;l++)
            ans += ino[l];
        
        return ans;
    }
};