/*
    A binary tree is named Even-Odd if it meets the following conditions:
    The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
    For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
    For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
    Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

    Example 1:
    Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
    Output: true
    Explanation: The node values on each level are:
    Level 0: [1]
    Level 1: [10,4]
    Level 2: [3,7,9]
    Level 3: [12,8,6,2]
    Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
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
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return false;
        
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> level;

        int lvl = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<int> res;

            while(n--) {
                TreeNode* curr = q.front();
                q.pop();

                if(lvl%2==0 && curr->val%2==0)
                    return false;
                if(lvl%2!=0 && curr->val%2!=0)
                    return false;

                res.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            lvl++;
            level.push_back(res);
        }

        for(int i=0;i<level.size();i++) {
            for(int j=0;j<level[i].size()-1;j++) {
                if(i%2==0) {
                    if(level[i][j] >= level[i][j+1])
                        return false;
                } else {
                    if(level[i][j] <= level[i][j+1])
                        return false;
                }
            }
        }

        return true;
    }
};