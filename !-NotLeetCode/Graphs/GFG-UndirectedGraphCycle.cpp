/*
    Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in 
    the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

    Example 1:
    Input:  V = 5, E = 5 adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
    Output: True
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfsCycle(int src, vector<int> adj[], vector<int>& visited) {
        visited[src] = 1;
        
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()) {
            int n = q.front().first;
            int p = q.front().second;
            q.pop();
            
            for(auto i : adj[n]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push({i, n});
                } else if(p != i)
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
            
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(bfsCycle(i, adj, vis))
                    return true;
            }
        }
        
        return false;
    }
};