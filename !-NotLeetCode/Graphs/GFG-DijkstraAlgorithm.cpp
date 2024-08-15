/*
    Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two 
    integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  
    edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to 
    return a list of integers denoting shortest distance between each node and Source vertex S.

    Note: The Graph doesn't contain any negative weight cycle.

    Example 1:
    Input: V = 2, adj [] = {{{1, 9}}, {{0, 9}}}, S = 0
    Output: 0 9
    Explanation: The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 1 is 9.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, INT_MAX);
        
        queue<pair<int, int>> q;
        q.push({S, 0});
        dist[S] = 0;
        
        while(!q.empty()) {
            int u = q.front().first;
            q.pop();
            
            for(auto j : adj[u]) {
                int v = j[0];
                int w = j[1];
                
                if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
                    dist[v] = dist[u] + w;
                    q.push({v, dist[v]});
                }
            }
        }
        
        for(int i=0; i<dist.size(); i++) {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        
        return dist;
    }
};