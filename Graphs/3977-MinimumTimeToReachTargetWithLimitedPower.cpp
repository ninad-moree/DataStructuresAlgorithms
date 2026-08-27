/*
    You are given a directed weighted graph with n nodes labeled from 0 to n - 1. The graph is represented by a 2D integer array edges, where edges[i] = [ui, vi, ti] indicates 
    a directed edge from node ui to node vi that takes ti seconds to traverse. You are also given an integer power representing the initial available power, and an integer 
    array cost of length n, where cost[u] represents the power required to forward the signal from node u through any one of its outgoing edges. You are given two integers 
    source and target. The signal starts at source at time 0 with power units of power and follows these rules: The signal may traverse a directed edge from node u only if the 
    remaining power is at least cost[u]. No power is consumed when the signal arrives at a node, unless it later leaves that node by traversing another edge.
    When the signal is forwarded from node u, the remaining power is decreased by cost[u] units. Traversing an edge edges[i] = [ui, vi, ti] increases the total time by ti 
    seconds. Return an integer array answer of size 2, where: answer[0] is the minimum time required for the signal to reach node target. answer[1] is the maximum remaining 
    power among all paths that achieve answer[0]. If the signal cannot reach target, return [-1, -1].

    Example 1:
    Input: n = 5, edges = [[0,1,1],[1,4,1],[0,2,1],[2,3,1],[3,4,1]], power = 4, cost = [2,3,1,1,1], source = 0, target = 4
    Output: [3,0]
    Explanation: The signal starts at node 0 with 4 units of power.
    The path 0 -> 1 -> 4 is not valid, because after leaving node 0, the signal has 2 units of power remaining, which is less than cost[1] = 3.
    The valid path 0 -> 2 -> 3 -> 4 takes a total time of 3. The total power consumed along this path is cost[0] + cost[2] + cost[3] = 4, leaving 0 remaining power.
    Hence, the answer is [3, 0].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adj[u].push_back({v, t});
        }

        // dist[node][remainingPower]
        vector<vector<long long>> dist( n, vector<long long>(power + 1, LLONG_MAX));

        // {time, -remainingPower, node}
        priority_queue< tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;

        dist[source][power] = 0;
        pq.push({0, -power, source});

        while (!pq.empty()) {
            tuple<long long, int, int> curr = pq.top();
            pq.pop();

            long long currTime = get<0>(curr);
            int negPower = get<1>(curr);
            int node = get<2>(curr);
            
            int currPower = -negPower;

            if (currTime != dist[node][currPower])
                continue;

            // If we reached target, no power is needed to leave it
            if (node == target) 
                return {currTime, currPower};

            // Cannot forward the signal
            if (currPower < cost[node])
                continue;

            int newPower = currPower - cost[node];

            for (auto i : adj[node]) {
                int v = i.first;
                int t = i.second;

                long long newTime = currTime + t;

                if (newTime < dist[v][newPower]) {
                    dist[v][newPower] = newTime;

                    pq.push({newTime, -newPower, v});
                }
            }
        }

        return {-1, -1};
    }
};