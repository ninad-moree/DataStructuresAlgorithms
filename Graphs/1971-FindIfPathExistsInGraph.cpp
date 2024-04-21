/*
    There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are 
    represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
    Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. You want to determine if there is a valid path 
    that exists from vertex source to vertex destination. Given edges and the integers n, source, and destination, return true if there is a 
    valid path from source to destination, or false otherwise.

    Example 1:
    Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
    Output: true
    Explanation: There are two paths from vertex 0 to vertex 2:
    - 0 → 1 → 2
    - 0 → 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(const vector<vector<int>>& adj, int curr, int destination, unordered_set<int>& visited) {
        if (curr == destination)
            return true;
        
        visited.insert(curr);
        
        for (int neighbor : adj[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(adj, neighbor, destination, visited))
                    return true;
            }
        }
        
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_set<int> visited;
        return dfs(adj, source, destination, visited);
    }
};