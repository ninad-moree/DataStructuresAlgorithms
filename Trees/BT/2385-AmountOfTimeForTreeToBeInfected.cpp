/*
    You are given the root of a binary tree with unique values, and an integer start. 
    At minute 0, an infection starts from the node with value start.
    Each minute, a node becomes infected if:
    The node is currently uninfected.
    The node is adjacent to an infected node.
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
    TreeNode* createMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*> &n2p) {
        TreeNode* res = NULL;

        queue<TreeNode*> q;
        q.push(root);
        n2p[root] = NULL;

        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if(front->val == start)
                res = front;
            
            if(front->left) {
                n2p[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                n2p[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int burnTree(TreeNode* root, map<TreeNode*, TreeNode*> &n2p) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;

        int time = 0;

        while(!q.empty()) {
            bool flag = 0;
            int size = q.size();

            for(int i=0;i<size;i++) {
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(n2p[front] && !visited[n2p[front]]) {
                    flag = 1;
                    q.push(n2p[front]);
                    visited[n2p[front]] = true;
                }
            }
            if(flag == 1)
                time++;
        }
        return time;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> n2p;
        TreeNode* targetNode = createMapping(root, start, n2p);
        int time = burnTree(targetNode, n2p);
        return time;
    }
};