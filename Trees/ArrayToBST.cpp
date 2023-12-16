/*
    Given an integer array nums where the elements are sorted in ascending order, 
    convert it to a height-balanced binary search tree.
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
    TreeNode* solve(vector<int>& arr, int start, int end) {
        if(start > end)
            return NULL;
        
        int mid = (start + end)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solve(arr, start, mid-1);
        root->right = solve(arr, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1);
    }
};