/*
    A maximum tree is a tree where every node has a value greater than any other value in its subtree. You are given the root of a maximum binary tree and an integer val. Just 
    as in the previous problem, the given tree was constructed from a list a (root = Construct(a)) recursively with the following Construct(a) routine: If a is empty, return 
    null. Otherwise, let a[i] be the largest element of a. Create a root node with the value a[i]. The left child of root will be Construct([a[0], a[1], ..., a[i - 1]]).
    The right child of root will be Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]). Return root. Note that we were not given a directly, only a root node root = 
    Construct(a). Suppose b is a copy of a with the value val appended to it. It is guaranteed that b has unique values. Return Construct(b).

    Example 1:
    Input: root = [4,1,3,null,null,2], val = 5
    Output: [5,4,null,1,3,null,null,2]
    Explanation: a = [1,4,2,3], b = [1,4,2,3,5]
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
    int getMaxIdx(vector<int>& nums, int l, int r) {
        int maxIdx = l;

        for(int i=l; i<r; i++) {
            if(nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        return maxIdx;
    }

    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if(l == r)
            return NULL;

        int maxIdx = getMaxIdx(nums, l, r);
        TreeNode* root = new TreeNode(nums[maxIdx]);

        root->left = buildTree(nums, l, maxIdx);
        root->right = buildTree(nums, maxIdx+1, r);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return buildTree(nums, 0, nums.size());
    }

    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> arr;
        inorder(root, arr);

        arr.push_back(val);

        return constructMaximumBinaryTree(arr);
    }
};