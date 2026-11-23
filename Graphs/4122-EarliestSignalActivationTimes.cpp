/*
    You are given an integer n and a directed graph with n nodes labeled from 0 to n - 1. The graph is represented by a 2D array edges, where edges[i] = [ui, vi, delayi] 
    indicates an edge from node ui to vi along which a signal takes delayi units of time to arrive. Node u is an incoming neighbor of node v if there is an edge from u to v.
    Node 0 is active at time 0, and all other nodes are initially inactive. When a node becomes active at time t, it immediately sends one signal along each of its outgoing 
    edges. Once active, a node remains active and does not send its signals again. A signal sent along an edge with delay d arrives at time t + d. You are also given an integer
    array requiredSignals of length n, where requiredSignals[i] is the number of distinct incoming neighbors of node i from which a signal must arrive before node i can 
    activate. An inactive node i becomes active at the earliest time t at which signals have arrived from at least requiredSignals[i] distinct incoming neighbors. Return an 
    array ans of length n where ans[i] is the earliest time node i becomes active. If node i never becomes active, ans[i] should be -1.
    Note: The value of requiredSignals[0] is irrelevant, since node 0 is active at time 0 and sends its outgoing signals at that time.

    Example 1:
    Input: n = 3, edges = [[0,1,1],[0,2,1]], requiredSignals = [1,1,2]
    Output: [0,1,-1]
    Explanation: Node 0 is active at time 0 and sends signals to nodes 1 and 2. At time 1, both signals arrive. Node 1 has received its required 1 signal, so it activates.
    Node 2 requires signals from 2 distinct incoming neighbors, but it has only one incoming neighbor. It never activates. Therefore, ans = [0, 1, -1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        // smallest delay for each (u, v)
        vector<unordered_map<int, int>> best(n);
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int d = i[2];

            if(!best[u].count(v) || best[u][v] > d)
                best[u][v] = d;
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // {time, node}

        vector<long long> ans(n, -1);
        vector<int> cnt(n);

        ans[0] = 0;
        for(auto i : best[0]) {
            int v = i.first;
            int d = i.second;

            pq.push({d, v});
        }

        while(!pq.empty()) {
            long long t = pq.top().first;
            int v = pq.top().second;
            pq.pop();

            if(ans[v] != -1)
                continue;

            cnt[v]++;
            if(cnt[v] >= requiredSignals[v]) {
                ans[v] = t;

                for(auto i : best[v]) {
                    int w = i.first;
                    int d = i.second;

                    pq.push({t + d, w});
                }
            }
        }

        return ans;
    }
};