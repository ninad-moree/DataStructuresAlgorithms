/*
    You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. 
    It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and 
    vice versa. Also, there are no self-loops present in the graph.

    For Example:
    If 'N' = 3 and edges = {{2,1}, {2,0}}.
    So, the adjacency list of the graph is stated below.
    0 → 2
    1 → 2
    2 → 0 → 1
*/

#include<bits/stdc++.h>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++) 
        adj[i].push_back(i);

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}