/*
    You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and 
    bi in the graph. Return the number of connected components in the graph.

    Example 1:
    Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> adj, vector<bool>& vis) {
        vis[node] = true;
        for(auto i : adj[node]) {
            if(!vis[i]) {
                vis[i] = true;
                dfs(i, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, 0);
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, edges, vis);
            }
        }

        return cnt;
    }
};