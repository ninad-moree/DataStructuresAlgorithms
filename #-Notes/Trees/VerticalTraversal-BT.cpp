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

vector<int> verticalTraversal(TreeNode* root) {
    if(!root)
        return {};
    
    unordered_map<int, unordered_map<int, vector<int>>> Nodes;
    queue<pair<TreeNode*, pair<int,int>>> q; // contains: node, {distance, level}
    vector<int> ans;

    q.push({root, {0,0}});

    while (!q.empty()) {
        pair<TreeNode*, pair<int, int>> temp = q.front();
        q.pop();

        TreeNode* front = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        Nodes[horizontalDistance][level].push_back(front->val);

        if(front->left)
            q.push({front->left, {horizontalDistance-1, level+1}});
        if(front->right)
            q.push({front->right, {horizontalDistance+1, level+1}});
    }

    for(auto i :Nodes) {
        for(auto j : i.second) {
            for(auto k: j.second) 
                ans.push_back(k);
        }
    }
    
    return ans;
}