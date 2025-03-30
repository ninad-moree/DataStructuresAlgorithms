/*
    You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs 
    are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two 
    intersections. You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between 
    intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to 
    intersection n - 1 in the shortest amount of time. Return the number of ways you can arrive at your destination in the shortest amount of 
    time. Since the answer may be large, return it modulo 109 + 7.

    Example 1:
    Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    Output: 4
    Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
    The four ways to get there in 7 minutes are:
    - 0 ➝ 6
    - 0 ➝ 4 ➝ 6
    - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
    - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        vector<vector<pair<int, int>>> adj(n);  

        for(int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();

            long long weight = f.first;
            long long node = f.second;

            for (auto i : adj[node]) {
                long long v = i.first;
                long long w = i.second;

                if(w + weight < dist[v]) {
                    dist[v] = w + weight;
                    pq.push({dist[v], v});
                    ways[v] = ways[node];
                } else if(w + weight == dist[v]) 
                    ways[v] = (ways[v] + ways[node])%MOD;
            }
        }

        return ways[n - 1] % MOD;
    }
};
