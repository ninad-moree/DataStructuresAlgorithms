/*
    You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1. You are also given a 2D integer array edges 
    where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti. Lastly, you are given three distinct integers src1, 
    src2, and dest denoting three distinct nodes of the graph. Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and 
    src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1. A subgraph is a graph whose vertices and edges are subsets of the original 
    graph. The weight of a subgraph is the sum of weights of its constituent edges.

    Example 1:
    Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
    Output: 9
    Explanation: The above figure represents the input graph. The blue edges represent one of the subgraphs that yield the optimal answer. Note that the subgraph 
    [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n) {
        vector<long long> dist(n, LLONG_MAX);

        // {dist, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto i : adj[node]) {
                int v = i.first;
                int dis = i.second;

                if(dist[v] == LLONG_MAX || dist[v] > d + dis) {
                    dist[v] = d + dis;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> revAdj(n);

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int d = i[2];

            adj[u].push_back({v, d});
            revAdj[v].push_back({u, d});
        }

        vector<long long> distS1 = dijkstra(src1, adj, n); // src1 --> other nodes;
        vector<long long> distS2 = dijkstra(src2, adj, n); // src2 --> other nodes;
        vector<long long> distDest = dijkstra(dest, revAdj, n); // dest --> other nodes;

        long long ans = LLONG_MAX;

        // i = meeting point;
        for(int i=0; i<n; i++) {
            if(distS1[i] == LLONG_MAX || distS2[i] == LLONG_MAX || distDest[i] == LLONG_MAX)
                continue;

            long long cost = distS1[i] + distS2[i] + distDest[i];

            ans = min(ans, cost);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};