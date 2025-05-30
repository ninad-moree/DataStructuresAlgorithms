/*
    You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge. The graph is represented with 
    a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from
    i, then edges[i] == -1. You are also given two integers node1 and node2. Return the index of the node that can be reached from both node1 and 
    node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple 
    answers, return the node with the smallest index, and if no possible answer exists, return -1. Note that edges may contain cycles.

    Example 1:
    Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
    Output: 2
    Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
    The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<vector<int>> adj, vector<int>& dist) {
        vector<int> b;
        queue<int> q;
        vector<int> vis(adj.size(), 0);

        q.push(node);
        vis[node] = 1;
        dist[node] = 0;

        while(!q.empty()) {
            int f = q.front();
            q.pop();

            for(auto i : adj[f]) {
                if(!vis[i]) {
                    dist[i] = dist[f] + 1;
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> adj(edges.size());

        for(int i=0; i<edges.size(); i++) {
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> d1(edges.size(), INT_MAX);
        vector<int> d2(edges.size(), INT_MAX);

        bfs(node1, adj, d1);
        bfs(node2, adj, d2);

        int minNode = -1;
        int mini = INT_MAX;

        for(int i=0; i<edges.size(); i++) {
            if(mini > max(d1[i], d2[i])) {
                mini = max(d1[i], d2[i]);
                minNode = i;
            }
        }

        return minNode;
    }
};