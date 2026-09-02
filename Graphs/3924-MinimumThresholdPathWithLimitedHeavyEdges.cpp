/*
    There is an undirected weighted graph with n nodes labeled from 0 to n - 1. The graph is represented by a 2D integer array edges, where each edge edges[i] = [ui, vi, w​​​​​​​i] 
    indicates that there is an undirected edge between nodes ui and vi with weight w​​​​​​​i. You are also given integers source, target and k. A threshold value determines whether an
    edge is considered light or heavy: An edge is light if its weight is less than or equal to threshold. An edge is heavy if its weight is greater than threshold.
    A path from source to target is valid if it contains at most k heavy edges. Return the minimum integer threshold such that at least one valid path exists from source to 
    target. If no such path exists, return -1.

    Example 1:​​​​​​​​​​​​​​
    Input: n = 6, edges = [[0,1,5],[1,2,3],[3,4,4],[4,5,1],[1,4,2]], source = 0, target = 3, k = 1
    Output: 4
    Explanation: The minimum threshold such that a path from node 0 to node 3 uses at most 1 heavy edge is 4.  Light edges: [1, 2, 3], [3, 4, 4], [4, 5, 1], [1, 4, 2] Heavy 
    edges: [0, 1, 5] A valid path is 0 → 1 → 4 → 3. It uses only 1 heavy edge ([0, 1, 5]), which satisfies the limit k = 1.
    Any smaller threshold would make it impossible to reach node 3 without exceeding 1 heavy edge.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int n, vector<vector<pair<int, int>>>& adj, int source, int target, int k, int threshold) {
        vector<int> vis(n, INT_MAX); // Minimum number of heavy edges used to reach each node
        queue<pair<int, int>> q; // {node, heavy edges used}

        q.push({source, 0});
        vis[source] = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int heavy = q.front().second;
            q.pop();

            if(node == target)
                return true;

            for(auto n : adj[node]) {
                int v = n.first;
                int w = n.second;

                int nextHeavy = heavy + (w > threshold);

                if(nextHeavy > k)
                    continue;

                if (vis[v] <= nextHeavy)
                    continue;

                vis[v] = nextHeavy;
                q.push({v, nextHeavy});
            }
        }

        return false;
    }

    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source == target)
            return 0;

        vector<vector<pair<int, int>>> adj(n);
        int l = 0;
        int h = INT_MIN;

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});

            l = min(l, w);
            h = max(h, w);
        }

        if(!bfs(n, adj, source, target, k, h))
            return -1;

        int ans = h;

        while(l <= h) {
            int mid = l + (h-l) / 2;

            if(bfs(n, adj, source, target, k, mid)) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid+1;
        }

        return ans;
    }
};