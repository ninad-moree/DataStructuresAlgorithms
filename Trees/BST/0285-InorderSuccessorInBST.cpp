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

class Solution {
public:
    int inOrderSuccessor(TreeNode *root, TreeNode *x) {
        TreeNode* succ = root;
        int ans = -1;
        
        while(succ != NULL) {
            if(succ->data <= x->data)
                succ = succ->right;
            else {
                ans = succ->data;
                succ = succ->left;
            } 
        }
        
        return ans;
    }
};