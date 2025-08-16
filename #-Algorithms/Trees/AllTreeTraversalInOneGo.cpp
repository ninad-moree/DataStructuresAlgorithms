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

vector<vector<int>> allTraversal(TreeNode* root) {
    stack<pair<TreeNode*, int>> st;
    vector<int> pre, ino, post;
    st.push({root, 1});

    while(!st.empty()) {
        auto top = st.top();
        st.pop();

        if(top.second == 1) {
            ino.push_back(top.first->val);
            top.second++;
            st.push(top);

            if(top.first->left != NULL)
                st.push({top.first->left, 1});
        } else if(top.second == 2) {
            pre.push_back(top.first->val);
            top.second++;
            st.push(top);

            if(top.first->right != NULL)
                st.push({top.first->right, 1});
        } else
            post.push_back(top.first->val);
    }

    return {pre, ino, post};
}