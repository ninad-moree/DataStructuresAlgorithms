/*
    Given the root of a binary tree, calculate the vertical order traversal of the binary tree. For each node at position (row, col), its left 
    and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).The vertical
    order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column  and ending on 
    the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
    Return the vertical order traversal of the binary tree.

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation:
    Column -1: Only node 9 is in this column.
    Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
    Column 1: Only node 20 is in this column.
    Column 2: Only node 7 is in this column.
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