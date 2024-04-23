/*
    A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without 
    simple cycles is a tree. Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates 
    that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select 
    a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum 
    height trees (MHTs). Return a list of all MHTs' root labels. You can return the answer in any order.

    Example 1:
    Input: n = 4, edges = [[1,0],[1,2],[1,3]]
    Output: [1]
    Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        
        vector<list<int>> adj(n);
        vector<int> degree(n, 0);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> leaf;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1)
                leaf.push(i);
        }

        int nodes = n;
        while(nodes > 2) {
            int leafCnt = leaf.size();
            nodes -= leafCnt;

            for(int i=0; i<leafCnt; i++) {
                int l = leaf.front();
                leaf.pop();

                for(int neigh : adj[l]) {
                    if(--degree[neigh] == 1)
                        leaf.push(neigh);
                }
            }
        }

        vector<int> ans;
        while(!leaf.empty()) {
            ans.push_back(leaf.front());
            leaf.pop();
        }

        return ans;
    }
};