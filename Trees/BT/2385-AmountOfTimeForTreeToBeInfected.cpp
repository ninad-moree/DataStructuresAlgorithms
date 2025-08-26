/*
    You are given the root of a binary tree with unique values, and an integer start.  At minute 0, an infection starts from the node with value start.
    Each minute, a node becomes infected if: The node is currently uninfected. The node is adjacent to an infected node.
    Return the number of minutes needed for the entire tree to be infected.

    Example 1:
    Input: root = [1,5,3,null,4,10,6,9,2], start = 3
    Output: 4
    Explanation: The following nodes are infected during:
    - Minute 0: Node 3
    - Minute 1: Nodes 1, 10 and 6
    - Minute 2: Node 5
    - Minute 3: Node 4
    - Minute 4: Nodes 9 and 2
    It takes 4 minutes for the whole tree to be infected so we return 4.
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
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode*& startNode, int start) {
        queue<TreeNode*> q;
        q.push({root});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            if(f->val == start)
                startNode = f;

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

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode;
        getParents(root, parent, startNode, start);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        int time = 0;

        q.push(startNode);
        vis[startNode] = true;

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto f = q.front();
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

            time++;
        }

        return time - 1;
    }
};