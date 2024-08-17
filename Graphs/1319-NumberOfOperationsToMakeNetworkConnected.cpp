/*
    There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] 
    represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
    You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place 
    them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order 
    to make all the computers connected. If it is not possible, return -1.

    Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for(auto i : adj[node]) {
            if(!visited[i]) 
                dfs(i, visited, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;

        int ans = 0;
        vector<bool> vis(n, false);

        vector<vector<int>> adj(n);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, vis, adj);
            }
        }

        return ans-1;
    }
};

