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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = true;

    void pushAll(TreeNode* node) {
        while(node != NULL) {
            st.push(node);
            if(reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(!reverse)
            pushAll(node->right);
        pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;

        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while(i < j) {
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = left.next();
            else
                j = right.next();
        }

        return false;
    }
};