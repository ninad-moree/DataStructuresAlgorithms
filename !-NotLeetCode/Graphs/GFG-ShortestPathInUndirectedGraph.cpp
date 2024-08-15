/*
    You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable 
    to reach any vertex, then return -1 for that vertex.

    Examples :
    Input: n = 9, m = 10, edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]], src=0
    Output: 0 1 2 1 2 3 3 4 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src) {
        vector<int> dist(N, INT_MAX);
        queue<pair<int, int>> q;
        vector<vector<int>> adj(N);
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        q.push({src, 0});
        dist[src] = 0;
        
        while(!q.empty()) {
            int u = q.front().first;
            q.pop();
            
            for(auto j : adj[u]) {
                int v = j;
                int w = 1;
                
                if(dist[u] != INT_MAX && dist[u]+w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push({v, dist[v]});
                }
            }
        }
        
        for(int i=0; i<dist.size(); i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        
        return dist;
    }
};