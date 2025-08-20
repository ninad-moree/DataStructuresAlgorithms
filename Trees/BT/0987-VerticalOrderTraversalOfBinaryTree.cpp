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

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {vertical, level}}
        map<int, map<int, multiset<int>>> mp; // {vertical, {level, {nodes}}}

        if(!root)   
            return ans;

        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            auto node = f.first;
            int vertical = f.second.first;
            int level = f.second.second;

            mp[vertical][level].insert(node->val);

            if(node->left) 
                q.push({node->left, {vertical-1, level+1}});

            if(node->right) 
                q.push({node->right, {vertical+1, level+1}});
        }

        for(auto i : mp) {
            vector<int> col;
            for(auto j : i.second) 
                col.insert(col.end(), j.second.begin(), j.second.end());
            ans.push_back(col);
        }

        return ans;
    }
};