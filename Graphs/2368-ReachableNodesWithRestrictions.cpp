/*
    There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates 
    that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes. Return the maximum number of 
    nodes you can reach from node 0 without visiting a restricted node. Note that node 0 will not be a restricted node.

    Example 1:
    Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
    Output: 4
    Explanation: The diagram above shows the tree. We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& restricted) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

        while(!q.empty()) {
            int n = q.front();
            q.pop();

            for(auto neigh : adj[n]) {
                if(!vis[neigh] && !vis[neigh] && restrictedSet.find(neigh) == restrictedSet.end()) {
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);

        for(auto i : edges) {
            int x = i[0];
            int y = i[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(0, adj, vis, restricted);

        int ans = 0;

        for(auto i : vis) {
            if(i == 1)
                ans++;
        }

        return ans;
    }
};