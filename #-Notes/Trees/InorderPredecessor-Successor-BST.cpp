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

pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
    TreeNode* temp = root;

    int predecessor = -1;
    int successor = -1;

    // searching the key
    while(temp->val != key) {
        if(temp->val > key) {
            successor = temp->val;
            temp = temp->left;
        }
        else {
            predecessor = temp->val;
            temp = temp->right;
        }
    }

    // predecessor
    TreeNode* leftTree = temp->left;
    while(leftTree != NULL) {
        predecessor = leftTree->val;
        leftTree = leftTree->right;
    }

    // successor
    TreeNode* rightTree = temp->right;
    while(rightTree != NULL) {
        successor = rightTree->val;
        rightTree = rightTree->left;
    }

    return {predecessor, successor};
}