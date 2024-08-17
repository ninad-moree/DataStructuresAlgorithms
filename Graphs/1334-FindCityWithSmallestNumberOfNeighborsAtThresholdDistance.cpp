/*
    There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and 
    weighted edge between cities fromi and toi, and given the integer distanceThreshold. Return the city with the smallest number of cities that 
    are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the 
    greatest number.

    Example 1:
    Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    Output: 3
    Explanation: The figure above describes the graph. 
    The neighboring cities at a distanceThreshold = 4 for each city are:
    City 0 -> [City 1, City 2] 
    City 1 -> [City 0, City 2, City 3] 
    City 2 -> [City 0, City 1, City 3] 
    City 3 -> [City 1, City 2] 
    Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstras(int node, vector<vector<pair<int, int>>> adj, int n) {
        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({node, 0});
        dist[node] = 0;

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            int n = f.first;
            int w = f.second;

            for(auto i : adj[n]) {
                int v = i.first;
                int wt = i.second;

                if(w + wt < dist[v]) {
                    dist[v] = w + wt;
                    q.push({v, dist[v]});
                }
            }
        }

        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(int i=0; i<n; i++) {
            vector<int> d = dijkstras(i, adj, n);
            dist[i] = d;
        }

        vector<pair<int, int>> city;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold && dist[i][j] != 0)
                    cnt++;
            }
            city.push_back({i, cnt});
        }

        int mini = INT_MAX;
        int ans = INT_MIN;

        for(auto i : city) {
            mini = min(mini, i.second);
            if(mini == i.second)
                ans = max(ans, i.first);
        }

        return ans;
    }
};