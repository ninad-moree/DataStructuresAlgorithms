#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return  parent[node] = findParent(parent, parent[node]); // path compression;
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u]<rank[v])
        parent[u] = v;
    else if(rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int kruskalsMST(vector<vector<int>> edges, int n) {
    vector<int> parent(n), rank(n);

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }  

    sort(edges.begin(), edges.end(),  comp);

    int ans = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if(u != v) {
            unionSet(u, v, parent, rank);
            ans += w;
        }
    }

    return ans;
}