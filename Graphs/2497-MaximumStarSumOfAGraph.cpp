/*
    There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the
    ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi. A star graph is a 
    subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common 
    node for all edges. The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node. The star sum is the sum of the values of all the nodes
    present in the star graph. Given an integer k, return the maximum star sum of a star graph containing at most k edges.

    Example 1:
    Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
    Output: 16
    Explanation: The above diagram represents the input graph. The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and
    4. It can be shown it is not possible to get a star graph with a sum greater than 16.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();

        vector<vector<pair<int, int>>> adj(n);

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int valU = vals[u];
            int valV = vals[v];

            adj[u].push_back({v, valV});
            adj[v].push_back({u, valU});
        }

        for(int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            int sum = vals[i];
            int cnt = min(k, (int)adj[i].size());

            for(int j=0; j<cnt; j++) {
                if(adj[i][j].second <= 0)
                    break;
                sum += adj[i][j].second;
            }
            
            ans =  max(ans, sum);
        }

        return ans;
    }
};