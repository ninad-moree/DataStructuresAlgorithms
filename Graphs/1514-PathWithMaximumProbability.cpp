/*
    You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge 
    connecting the nodes a and b with a probability of success of traversing that edge succProb[i]. Given two nodes start and end, find the path with 
    the maximum probability of success to go from start to end and return its success probability. If there is no path from start to end, return 0. Your
    answer will be accepted if it differs from the correct answer by at most 1e-5.

    Example 1:
    Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
    Output: 0.25000
    Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({succProb[i], v});
            adj[v].push_back({succProb[i], u});
        }

        vector<double> probs(n, 0);

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        probs[start_node] = 1.0;

        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int u = t.second;
            double currProb = t.first;

            if(u == end_node)
                return currProb;

            for(auto i : adj[u]) {
                int v = i.second;
                double prob = i.first;

                double newProb = currProb * prob;
                if(newProb > probs[v]) {
                    probs[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;
    }
};