/*
    You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where 
    edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi. You are also given a string labels of length n, where labels[i] is the character 
    assigned to node i, and an integer k. Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along 
    the path contains at most k consecutive identical characters. If no valid path exists, return -1.

    Example 1:
    Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
    Output: 3
    Explanation: The optimal valid path from node 0 to node 2 is as follows: Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
    The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];

            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // {weight, node, consecutive cnt}
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX)); // dist[node][consecutive] = minWeight

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            tuple<long long, int, int> curr = pq.top();
            pq.pop();

            int currWt = get<0>(curr);
            int node = get<1>(curr);
            int consec = get<2>(curr);
            
            if(currWt != dist[node][consec])
                continue;

            if(node == n-1)
                return currWt;
                
            for(auto i : adj[node]) {
                int v = i.first;
                int w = i.second;

                int newConsec = 0;

                if(labels[v] == labels[node])
                    newConsec = consec + 1;
                else
                    newConsec = 1;

                if(newConsec > k)
                    continue;

                int newDist = currWt + w;

                if(newDist < dist[v][newConsec]) {
                    dist[v][newConsec] = newDist;
                    pq.push({newDist, v, newConsec});
                }
            }
        }

        return -1;
    }
};