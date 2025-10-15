/*
    There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection 
    between servers ai and bi. Any server can reach other servers directly or indirectly through the network. A critical connection is a connection that, if removed, will make 
    some servers unable to reach some other server. Return all critical connections in the network in any order.

    Example 1:
    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: [[3,1]] is also accepted.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 1;
public:
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& time, vector<int>& lowestTime, vector<vector<int>>& bridges) {
        vis[node] = 1;
        time[node] = lowestTime[node] = timer;
        timer++;

        for(auto i : adj[node]) {
            if(i == parent)
                continue;
            if(vis[i] == 0) {
                dfs(i, node, vis, adj, time, lowestTime, bridges);
                lowestTime[node] =  min(lowestTime[node], lowestTime[i]);

                if(lowestTime[i] > time[node]) 
                    bridges.push_back({i, node});
            } else 
                lowestTime[node] = min(lowestTime[node], time[i]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        vector<int> time(n);
        vector<int> lowestTime(n);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, time, lowestTime, bridges);

        return bridges;
    }
};