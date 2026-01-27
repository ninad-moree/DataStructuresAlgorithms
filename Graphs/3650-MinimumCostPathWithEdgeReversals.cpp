/*
    You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to 
    node vi with cost wi. Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its 
    incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it. The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
    Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

    Example 1:
    Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    Output: 5
    Explanation:
    Use the path 0 → 1 (cost 3). At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2. Total cost is 3 + 2 = 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();

            int node = f.first;
            int wt = f.second;

            if(node == n-1)
                return dist[node];

            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;

                if(dist[v] > dist[node] + w) {
                    dist[v] = dist[node] + w;
                    pq.push({v, dist[v]});
                }
            }
        }

        return -1;
    }
};