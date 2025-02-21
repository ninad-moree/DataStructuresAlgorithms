/*
    Given a binary tree with the following rules: root.val == 0, For any treeNode:
    If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
    Now the binary tree is contaminated, which means all treeNode.val have been changed to -1. Implement the FindElements class:
    FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it. 
    bool find(int target) Returns true if the target value exists in the recovered binary tree.

    Example 1:
    Input: ["FindElements","find","find"], [[[-1,null,-1]],[1],[2]]
    Output: [null,false,true]
    Explanation:
    FindElements findElements = new FindElements([-1,null,-1]); 
    findElements.find(1); // return False 
    findElements.find(2); // return True 
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

class FindElements {
public:
    unordered_map<int, int> mp;

    FindElements(TreeNode* root) {
        bfs(root);
    }
    
    bool find(int target) {
        return mp.find(target) != mp.end();
    }

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);

        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();

            mp[f->val]++;

            if(f->left) {
                f->left->val = f->val * 2 + 1;
                q.push(f->left);
            }

            if(f->right) {
                f->right->val = f->val * 2 + 2;
                q.push(f->right);
            }
        }
    }
};
    