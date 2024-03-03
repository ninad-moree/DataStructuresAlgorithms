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

void solve(TreeNode* root, int sum, int& maxSum, int len, int& maxLen) {
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
            maxSum = max(sum, maxSum);
        
        return;
    }

    sum += root->val;

    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int sumOfLongestPath(TreeNode* root) {
    int len = 0;
    int maxLen = 0;
    
    int sum = 0;
    int maxSum = INT_MIN;

    (root, sum, maxSum, len, maxLen);

    return maxSum;
}