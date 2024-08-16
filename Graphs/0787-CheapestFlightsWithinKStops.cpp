/*
    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] 
    indicates that there is a flight from city fromi to city toi with cost pricei.
    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is 
    no such route, return -1.

    Example 1:
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
    Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];

            adj[u].push_back({v, d});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            int node = f.first;
            int stops = f.second.first;
            int weight = f.second.second;

            if(stops > k)
                continue;

            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;

                if(weight + w < dist[v] && stops <= k) {
                    dist[v] = w + weight;
                    q.push({v, {stops+1, dist[v]}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};