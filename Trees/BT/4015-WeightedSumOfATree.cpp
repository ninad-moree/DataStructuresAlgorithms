/*
    You are given an integer array parent of length n representing a rooted tree with nodes labeled from 0 to n - 1. The tree is rooted at node 0, so parent[0] = -1. For 
    each node i where 1 <= i <= n - 1, parent[i] denotes the parent of node i. You are also given an integer array nums of length n, where nums[i] denotes the value of node
    i. The weight of a node i at depth d is nums[i] * (h - d + 1), where h is the height of the tree. Return the sum of the weights of all nodes in the tree. The depth of a
    node is the number of nodes on the path from the root to that node, inclusive, with the root having depth 1. The height of the tree is the maximum depth among all nodes
    in the tree.

    Example 1:
    Input: parent = [-1,0,0,0,2,2], nums = [5,2,3,1,4,6]
    Output: 37
    Explanation: The height of the tree is 3. The sum of all node weights is 15 + 4 + 6 + 2 + 4 + 6 = 37.
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
    unordered_map<int, int> bfs(int start, int& lvl, unordered_map<int, vector<int>> mp) {
        queue<int> q;
        q.push(start);

        unordered_map<int, int> level; // {node --> depth}

        while(!q.empty()) {
            int s = q.size();
            
            while(s) {
                int node = q.front();
                q.pop();

                level[node] = lvl;

                for(auto i : mp[node]) 
                    q.push(i);

                s--;
            }

            lvl++;
        }

        return level;

    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();   

        unordered_map<int, vector<int>> mp; // node -> {children};
        for(int i=1; i<n; i++) 
            mp[parent[i]].push_back(i);
        
        int lvl = 1;
        unordered_map<int, int> level = bfs(0, lvl, mp);

        int height = lvl - 1;
        long long ans = 0;

        for(int i=0; i<n; i++) {
            int node = i;
            int d = level[node];

            ans += 1LL * nums[i] * (height - d + 1);
        }

        return ans;
    }
};