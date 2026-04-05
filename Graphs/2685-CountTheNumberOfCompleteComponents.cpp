/*
    You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes 
    that there exists an undirected edge connecting vertices ai and bi. Return the number of complete connected components of the graph. A connected component is a subgraph of a
    graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph. A connected component is 
    said to be complete if there exists an edge between every pair of its vertices.

    Example 1:
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
    Explanation: From the picture above, one can see that all of the components of this graph are complete.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& ans) {
        vector<int> component;
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()) {
            int n = q.front();
            q.pop();
            component.push_back(n);

            for(auto neigh : adj[n]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }

        bool isComplete = true;
        for(auto j : component) {
            if(adj[j].size() != component.size() - 1) {
                isComplete = false;
                break;
            }
        }

        if(isComplete)
            ans++;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            int x = i[0];
            int y = i[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> vis(n);
        int ans = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                bfs(i, adj, vis, ans);
            }
        }

        return ans;
    }
};