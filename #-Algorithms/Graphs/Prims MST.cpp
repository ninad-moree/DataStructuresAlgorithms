#include <bits/stdc++.h>
using namespace std;

vector<pair< pair<int, int>, int>> primsAlgo(int nodes, int edges, vector<pair< pair<int,int>, int>> graph) {
    // adj list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<graph.size(); i++) {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        int w = graph[i].second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key (nodes, INT_MAX);
    vector<bool> mst (nodes, false);
    vector<int> parent (nodes, -1);

    key[0] = 0;
    parent[0] = -1;

    for(int i=1; i<nodes; i++) {
        int mini = INT_MAX;
        int u;

        // finding the min node
        for(int v=0; v<nodes; v++) {
            if(mst[v]==false && key[v] < mini) {
                mini = key[v];
                u = v;
            }
        }

        // exploring the neighbors of min node
        mst[u] = true;
        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if(mst[v]==false && w<key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair< pair<int, int>, int>> ans;
    for(int i=1; i<nodes; i++) {
        ans.push_back({{parent[i], i} , key[i]});
    }

    return ans;
}