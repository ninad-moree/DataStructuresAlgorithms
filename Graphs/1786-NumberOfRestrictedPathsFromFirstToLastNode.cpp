/*
    There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where 
    each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti. A path from node start to node end is a sequence of 
    nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1. The distance of a path is the sum of the weights
    on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that 
    distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1. Return the number of restricted paths from node 1 to node n. Since that number may be too large,
    return it modulo 109 + 7.

    Example 1:
    Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
    Output: 3
    Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
    1) 1 --> 2 --> 5, 2) 1 --> 2 --> 3 --> 5, 3) 1 --> 3 --> 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> dijsktras(int src, vector<vector<pair<int, int>>>& adj, int n) {
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(auto p : adj[node]) {
                int v = p.first;
                int w = p.second;

                if(dist[v] > w + d) {
                    dist[v] = w + d;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int solve(int node, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& dp) {
        if(node == dist.size() - 1)
            return 1;

        if(dp[node] != -1)
            return dp[node];

        int ans = 0;

        for(auto i : adj[node]) {
            int v = i.first;

            if(dist[node] > dist[v])
                ans = (ans + solve(v, adj, dist, dp)) % MOD;
        }

        return dp[node] = ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist = dijsktras(n, adj, n);

        vector<int> dp(n + 1, -1);

        return solve(1, adj, dist, dp);
    }
};