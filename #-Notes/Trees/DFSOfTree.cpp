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

void DFS(TreeNode* root) {
    if(!root)
        return;
    
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        cout<<node->val<<" ";

        if(node->left)
            st.push(node->left);
        if(node->right)
            st.push(node->right);
    }
}