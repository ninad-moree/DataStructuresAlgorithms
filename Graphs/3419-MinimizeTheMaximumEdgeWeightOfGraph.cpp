/*
    You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. The graph is represented by a 2D integer array edges,
    where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi. You have to remove some edges from this graph (possibly none), so
    that it satisfies the following conditions: Node 0 must be reachable from all other nodes. The maximum edge weight in the resulting graph is minimized. Each node has at most
    threshold outgoing edges. Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be 
    satisfied, return -1.

    Example 1:
    Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
    Output: 1
    Explanation: Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int maxWt = 0;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n);
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{weight, node}
        pq.push({0, 0});

        while(!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node])
                continue;
            vis[node] = 1;

            maxWt = max(maxWt, wt);

            for(auto neigh : adj[node]) {
                int n = neigh.first;
                int w = neigh.second;

                if(!vis[n])
                    pq.push({w, n});
            }
        }

        for(auto i : vis) {
            if(i == 0)
                return -1;
        }

        return maxWt;
    }
};