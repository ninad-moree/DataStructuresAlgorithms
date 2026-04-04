/*
    You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there
    is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected. The score of a path between two cities is
    defined as the minimum distance of a road in this path. Return the minimum possible score of a path between cities 1 and n.
    A path is a sequence of roads between two cities. It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the
    path. The test cases are generated such that there is at least one path between 1 and n.

    Example 1:
    Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    Output: 5
    Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5. It can be shown that no other path has less score.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, int& ans) {
        if(vis[node])
            return;

        vis[node] = 1;

        for(auto i : adj[node]) {
            int neigh = i.first;
            int wt = i.second;

            ans = min(ans, wt);
            dfs(neigh, adj, vis, ans);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> vis(n+1);

        for(auto i : roads) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int ans = INT_MAX;

        dfs(1, adj, vis, ans);

        return ans;
    }
};