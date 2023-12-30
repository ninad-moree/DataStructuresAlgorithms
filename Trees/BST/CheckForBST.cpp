/*
    Given the root of a binary tree. Check whether it is a BST or not.
    Note: We are considering that BSTs can not contain duplicate Nodes.

    A BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    
    Example 1:
    Input:
       2
     /   \
    1     3
    Output: 1 
    Explanation: The left subtree of root node contains node with key lesser than the root nodes key and  the right subtree of 
    root node contains node with key greater than the root nodes key. Hence, the tree is a BST.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node* root, int minValue, int maxValue) {
        if (root == NULL)
            return true;

        if (root->data < minValue || root->data > maxValue) 
            return false;

        return isBSTUtil(root->left, minValue, root->data - 1) &&  isBSTUtil(root->right, root->data + 1, maxValue);  
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};