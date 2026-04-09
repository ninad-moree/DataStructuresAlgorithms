/*
    You are given an integer n and a directed graph with n nodes labeled from 0 to n - 1. This is represented by a 2D array edges, where edges[i] = [ui, vi, starti, endi] 
    indicates an edge from node ui to vi that can only be used at any integer time t such that starti <= t <= endi. You start at node 0 at time 0. In one unit of time, you can 
    either: Wait at your current node without moving, or Travel along an outgoing edge from your current node if the current time t satisfies starti <= t <= endi.
    Return the minimum time required to reach node n - 1. If it is impossible, return -1.

    Example 1:
    Input: n = 3, edges = [[0,1,0,1],[1,2,2,5]]
    Output: 3
    Explanation: The optimal path is: At time t = 0, take the edge (0 → 1) which is available from 0 to 1. You arrive at node 1 at time t = 1, then wait until t = 2.
    At time t = 2, take the edge (1 → 2) which is available from 2 to 5. You arrive at node 2 at time 3. Hence, the minimum time to reach node 2 is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n); // {node, start, end}
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int st = i[2];
            int en = i[3];

            adj[u].push_back({v, st, en});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {node, time};
        vector<int> vis(n);
        pq.push({0, 0});

        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            if(node == n-1)
                return time;

            if(vis[node])
                continue;
            vis[node] = 1;

            for(auto n : adj[node]) {
                int v = n[0];
                int st = n[1];
                int end = n[2];

                if(time <= end) {
                    int nextTime = max(st, time) + 1;

                    if(!vis[v]) 
                        pq.push({nextTime, v});
                }
            }
        }

        return -1;
    }
};