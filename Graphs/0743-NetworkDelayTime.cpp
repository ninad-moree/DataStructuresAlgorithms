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
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto i : adj[node]) {
                int v = i.first;
                int t = i.second;

                if(dist[v] > time + t) {
                    dist[v] = time + t;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<dist.size(); i++) {
            if(dist[i] == INT_MAX)
                return -1;
            else 
                ans = max(ans, dist[i]);
        }

        return ans;
    }
};