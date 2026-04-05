/*
    There is an undirected graph of n nodes. You are given a 2D array edges, where edges[i] = [ui, vi, lengthi] describes an edge between node ui and node vi with a traversal 
    time of lengthi units. Additionally, you are given an array disappear, where disappear[i] denotes the time when the node i disappears from the graph and you won't be able to
    visit it. Note that the graph might be disconnected and might contain multiple edges. Return the array answer, with answer[i] denoting the minimum units of time required to 
    reach node i from node 0. If node i is unreachable from node 0 then answer[i] is -1.

    Example 1:
    Input: n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]
    Output: [0,-1,4]
    Explanation: We are starting our journey from node 0, and our goal is to find the minimum time required to reach each node before it disappears.
    For node 0, we don't need any time as it is our starting point. For node 1, we need at least 2 units of time to traverse edges[0]. Unfortunately, it disappears at that 
    moment, so we won't be able to visit it. For node 2, we need at least 4 units of time to traverse edges[2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstras(int src, vector<vector<pair<int, int>>>& adj, vector<int>& disappear) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(adj.size(), INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            if(time > dist[node]) 
                continue;

            for(auto neigh : adj[node]) {
                int v = neigh.second;
                int t = neigh.first;
                int disT = disappear[v];

                if(time + t < dist[v] && disT > time + t) {
                    dist[v] = time + t;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n); // {time, node}

        for(auto i : edges) {
            int x = i[0];
            int y = i[1];
            int time = i[2];

            adj[x].push_back({time, y});
            adj[y].push_back({time, x});
        }

        vector<int> ans = dijkstras(0, adj, disappear);

        for(int i=0; i<n; i++) {
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        }

        return ans;
    }
};