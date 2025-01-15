#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstars(vector<vector<int>>& edges, int vertices, int noOfEdges, int source) {
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<noOfEdges; i++) {
        int u = edges[i][0]; // node 1
        int v = edges[i][1]; // node 2
        int w = edges[i][2]; // weight

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices, INT_MAX);

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while(!st.empty()) {
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        for(auto neighbor : adj[topNode]) {
            if(nodeDist + neighbor.second < dist[neighbor.first]) {
                auto rec = st.find({dist[neighbor.first], neighbor.first});
                if(rec != st.end()) {
                    st.erase(rec);
                }
                dist[neighbor.first] =  nodeDist + neighbor.second;
                st.insert({dist[neighbor.first], neighbor.first});
            }
        }
    }

    return dist;
}