/*
    You are given an integer n and a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1. This is represented by a 2D array edges, where edges[i] = [ui, vi, wi] 
    indicates a directed edge from node ui to vi with weight wi. You are also given two integers, k and t. Your task is to determine the maximum possible sum of edge weights for
    any path in the graph such that: The path contains exactly k edges. The total sum of edge weights in the path is strictly less than t.
    Return the maximum possible sum of weights for such a path. If no such path exists, return -1.

    Example 1:
    Input: n = 3, edges = [[0,1,1],[1,2,2]], k = 2, t = 4
    Output: 3
    Explanation: The only path with k = 2 edges is 0 -> 1 -> 2 with weight 1 + 2 = 3 < t. Thus, the maximum possible sum of weights less than t is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(k == 0)
            return 0;

        vector<vector<pair<int, int>>> adj(n);
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
        }

        unordered_map<int, unordered_map<int, unordered_map<int, int>>> vis; // {edges, {destinationNode, {sourceNode, pathSum}}}
        queue<vector<int>> q; // {edges, pathSum, node};
        for(int i=0; i<n; i++)
            q.push({0, 0, i});

        int ans = -1;

        while(!q.empty()) {
            int edges = q.front()[0];
            int pathSum = q.front()[1];
            int node = q.front()[2];
            q.pop();

            if(edges >= k) {
                if(pathSum > 0)
                    ans = max(ans, pathSum);
                continue;
            }

            for(auto n : adj[node]) {
                int v = n.first;
                int wt = n.second;

                if(vis[edges+1][v][node] < pathSum + wt && pathSum + wt < t) {
                    vis[edges+1][v][node] = pathSum + wt;
                    q.push({edges+1, vis[edges+1][v][node], v});
                }
            }
        }

        return ans;
    }
};