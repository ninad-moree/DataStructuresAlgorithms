/*
    Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

    Example 1:
    Input: root1 = [2,1,4], root2 = [1,0,3]
    Output: [0,1,1,2,3,4]
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
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1;
        vector<int> in2;

        inorder(root1, in1);
        inorder(root2, in2);

        int i = 0;
        int j = 0;

        vector<int> ans;

        while(i < in1.size() && j < in2.size()) {
            if(in1[i] < in2[j]) {
                ans.push_back(in1[i]);
                i++;
            } else {
                ans.push_back(in2[j]);
                j++;
            }
        }

        while(i < in1.size()) {
            ans.push_back(in1[i]);
            i++;
        }

        while(j < in2.size()) {
            ans.push_back(in2[j]);
            j++;
        }

        return ans;
    }
};