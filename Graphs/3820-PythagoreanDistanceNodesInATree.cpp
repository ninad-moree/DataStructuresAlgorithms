/*
    You are given an integer n and an undirected tree with n nodes numbered from 0 to n - 1. The tree is represented by a 2D array edges of length n - 1, where edges[i] = 
    [ui, vi] indicates an undirected edge between ui and vi. You are also given three distinct target nodes x, y, and z. For any node u in the tree:
    Let dx be the distance from u to node x. Let dy be the distance from u to node y. Let dz be the distance from u to node z The node u is called special if the three 
    distances form a Pythagorean Triplet. Return an integer denoting the number of special nodes in the tree. A Pythagorean triplet consists of three integers a, b, and c which,
    when sorted in ascending order, satisfy a2 + b2 = c2. The distance between two nodes in a tree is the number of edges on the unique path between them.

    Example 1:
    Input: n = 4, edges = [[0,1],[0,2],[0,3]], x = 1, y = 2, z = 3
    Output: 3
    Explanation: For each node, we compute its distances to nodes x = 1, y = 2, and z = 3. Node 0 has distances 1, 1, and 1. After sorting, the distances are 1, 1, and 1, which
    do not satisfy the Pythagorean condition. Node 1 has distances 0, 2, and 2. After sorting, the distances are 0, 2, and 2. Since 02 + 22 = 22, node 1 is special. Node 2 has 
    distances 2, 0, and 2. After sorting, the distances are 0, 2, and 2. Since 02 + 22 = 22, node 2 is special. Node 3 has distances 2, 2, and 0. After sorting, the distances 
    are 0, 2, and 2. This also satisfies the Pythagorean condition. Therefore, nodes 1, 2, and 3 are special, and the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateDist(int src, vector<vector<pair<int, int>>>& adj) {
        queue<int> q;
        q.push(src);

        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto i : adj[u]) {
                int v = i.first;
                int w = i.second;

                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }

        return dist;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> dist(n);
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }

        int ans = 0;

        vector<int> dx = calculateDist(x, adj);
        vector<int> dy = calculateDist(y, adj);
        vector<int> dz = calculateDist(z, adj);

        for (int i = 0; i < n; i++) {
            long long a = dx[i];
            long long b = dy[i];
            long long c = dz[i];

            if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) 
                ans++;
        }

        return ans;
    }
};