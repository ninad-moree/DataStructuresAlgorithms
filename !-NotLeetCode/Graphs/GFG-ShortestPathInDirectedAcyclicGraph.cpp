/*
    Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a 
    directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

    Example1:
    Input: N = 4, M = 2, edge = [[0,1,2],[0,2,1]]
    Output: 0 2 1 -1
    Explanation:
    Shortest path from 0 to 1 is 0->1 with edge weight 2.  Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, 
    so it's -1 for 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
        vector<int> dist(N, INT_MAX);
        vector<vector<pair<int, int>>> adj(N);
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        queue<pair<int, int>> q;
        q.push({0, -1});
        
        dist[0] = 0;
        
        while(!q.empty()) {
            int u = q.front().first;
            q.pop();
            
            for(auto j : adj[u]) {
                int v = j.first;
                int w = j.second;
                
                if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
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