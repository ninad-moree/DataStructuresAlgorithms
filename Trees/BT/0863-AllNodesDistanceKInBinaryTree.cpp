/*
    Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a 
    distance k from the target node. You can return the answer in any order.

    Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
    Output: [7,4,1]
    Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
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
    void getParents(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()) {
            TreeNode* f = q.front();
            q.pop();

            if(f->left) {
                parent[f->left] = f;
                q.push(f->left);
            }
            if(f->right) {
                parent[f->right] = f;
                q.push(f->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;

        q.push(target);
        vis[target] = true;
        int lvl = 0;

        while(!q.empty()) {
            int s = q.size();
            if(lvl == k)
                break;

            lvl++;

            for(int i=0; i<s; i++) {
                TreeNode* f = q.front();
                q.pop();

                if(f->left && !vis[f->left]) {
                    q.push(f->left);
                    vis[f->left] = true;
                }
                if(f->right && !vis[f->right]) {
                    q.push(f->right);
                    vis[f->right] = true;
                }

                if(parent[f] && !vis[parent[f]]) {
                    q.push(parent[f]);
                    vis[parent[f]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            ans.push_back(f->val);
        }

        return ans;
    }
};