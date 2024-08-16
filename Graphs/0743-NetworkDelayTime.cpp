/*
    You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges 
    times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to
    target. We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is 
    impossible for all the n nodes to receive the signal, return -1.

    Example 1:
    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n+1);

        dist[0] = -1;

        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        dist[k] = 0;
        q.push({k, 0});

        while(!q.empty()) {
            auto f = q.front();
            q.pop();

            int node = f.first;
            int weight = f.second;

            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;

                if(w + weight < dist[v]) {
                    dist[v] = w +weight;
                    q.push({v, dist[v]});
                }
            }
        }

        int ans = dist[1];
        for(auto i : dist) 
            ans = max(ans, i); 
        
        return ans == INT_MAX ? -1 : ans;
    }
};