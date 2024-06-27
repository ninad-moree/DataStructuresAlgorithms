/*
    There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly 
    n - 1 edges that connect the center node with every other node. nYou are given a 2D integer array edges where each edges[i] = [ui, vi] indicates 
    that there is an edge between the nodes ui and vi. Return the center of the given star graph.

    Example 1:
    Input: edges = [[1,2],[2,3],[4,2]]
    Output: 2
    Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n+1);

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u-1].push_back(v);
            adj[v-1].push_back(u);
        }


        for(int i=0; i<adj.size(); i++) {
            if(adj[i].size() == n) {
                return i+1;
            }
        }

        return -1;
    }
};