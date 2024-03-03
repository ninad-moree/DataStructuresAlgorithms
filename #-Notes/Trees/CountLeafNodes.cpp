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

void inorder(TreeNode* root, int& cnt) {
    if (!root) 
        return;
    
    inorder(root->left, cnt);

    if(root->left == NULL && root->right == NULL)
        cnt++;
    
    inorder(root->right, cnt);
}

int leafNodes(TreeNode* root) {
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}