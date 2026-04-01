/*
    You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi]. The cost of connecting two points [xi, yi] and 
    [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val. Return the minimum cost to make all points connected. 
    All points are connected if there is exactly one simple path between any two points.

    Example 1:
    Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    Output: 20
    Explanation:  We can connect the points as shown above to get the minimum cost of 20. Notice that there is a unique path between every pair of points.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int n, vector<vector<pair<int, int>>> adj) {
        vector<int> vis(n, 0);
        
        // weight, node, parent
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, -1});
        int dist = 0;
        
        vector<pair<int, int>> mst;
        
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            
            int weight = f[0];
            int node = f[1];
            int parent = f[2];
            
            if(vis[node])
                continue;
            
            vis[node] = 1;
            dist += weight;
            
            if(parent != -1)
                mst.push_back({node, parent});
                
            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;
                
                if(!vis[v]) {
                    pq.push({w, v, node});
                }
            }
        }
        
        return dist;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int ans = spanningTree(n, adj);

        return ans;
    }
};