/*
    Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest
    number of nodes. A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:
    The left subtree values are less than the value of their parent (root) node's value.
    The right subtree values are greater than the value of their parent (root) node's value.

    Example 1:
    Input: root = [10,5,15,1,8,null,7]
    Output: 3
    Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
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

class Node {
public:
    int mini, maxi, size;
    
    Node(int mini, int maxi, int size) {
        this->maxi = maxi;
        this->mini = mini;
        this->size = size;
    }
};

class Solution {
public:
    Node largestBSTHelper(TreeNode* root) {
        if(!root)
            return Node(INT_MAX, INT_MIN, 0);

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        if(left.maxi < root->val && root->val < right.mini) 
            return Node(min(left.mini, root->val), max(right.maxi, root->val), left.size + right.size + 1 );

        return Node(INT_MIN, INT_MAX, max(left.size, right.size));
    }

    int largestBst(TreeNode* root) {
        return largestBSTHelper(root).size;
    }
};