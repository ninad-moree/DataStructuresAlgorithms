/*
    You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be 
    self-edges and parallel edges. You are given two arrays redEdges and blueEdges where:
    redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
    blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
    Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if 
    such a path does not exist.

    Example 1:
    Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
    Output: [0,1,-1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<pair<int, int>>>& adj, vector<vector<bool>>& vis, vector<int>& ans) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        vis[0][0] = 1;
        vis[0][1] = 1;

        int dist = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();

                if(ans[node] == -1)
                    ans[node] = dist;

                for(auto i : adj[node]) {
                    int nextNode = i.first;
                    int nextColor = i.second;

                    if(nextColor != color && !vis[nextNode][nextColor]) {
                        vis[nextNode][nextColor] = true;
                        q.push({nextNode, nextColor});
                    }
                }
            }

            dist++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        vector<int> ans(n, -1);

        for(auto i : redEdges) {
            int x = i[0];
            int y = i[1];

            adj[x].push_back({y, 0});
        }

        for(auto i : blueEdges) {
            int x = i[0];
            int y = i[1];

            adj[x].push_back({y, 1});
        }

        bfs(adj, vis, ans);

        return ans;
    }
};