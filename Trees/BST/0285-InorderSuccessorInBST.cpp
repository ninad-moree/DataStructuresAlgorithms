/*
    Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
    The successor of a node p is the node with the smallest key greater than p.val.

    Example 1:
    Input: root = [2,1,3], p = 1
    Output: 2
    Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pred = -1;
    int succ = -1;

    TreeNode* pre = NULL;
    TreeNode* suc = NULL;

    TreeNode* temp1 = root;
    while (temp1) {
        if (temp1->data > key) {
            suc = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }

    TreeNode* temp2 = root;
    while (temp2) {
        if (temp2->data < key) {
            pre = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }

    if(pre != NULL)
        pred = pre->data;
    if(suc != NULL)
        succ = suc->data;

    return {pred, succ};
}