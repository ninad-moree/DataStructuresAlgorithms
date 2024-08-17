/*
    Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in 
    the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing 
    vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting 
    the weight of the edge.

    Example 1:
    Input:
    3 3
    0 1 5
    1 2 3
    0 2 1
    Output: 4
    Explanation:
    The Spanning Tree resulting in a weight of 4 is shown above.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vis(V, 0);
        
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
                int v = i[0];
                int w = i[1];
                
                if(!vis[v]) {
                    pq.push({w, v, node});
                }
            }
        }
        
        return dist;
    }
};