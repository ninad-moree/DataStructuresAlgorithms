/*
    Shortes Distance between source and destination.
    Nodes are from 1 to n (nodes).
*/

#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int nodes, int e, int src, int dest, vector<vector<int>> edges) {
    vector<int> dist(nodes + 1, INT_MAX);

    dist[src] = 0;

    for(int i=1; i<=nodes; i++) {
        for(int j=0; j<e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }

    // for negative cycle
    bool flag = 0;
    for(int j=0; j<e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
            flag = 1;
    }

    return flag == 0 ? dist[dest] : -1;
}