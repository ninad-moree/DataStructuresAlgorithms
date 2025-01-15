#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> edges, int nodes, int noOfEdges) {
    // creating an adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<noOfEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i=0; i<nodes; i++) {
        if(!visited[i])
            topoSort(i, visited, s, adjList);
    }

    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

void topoSort(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<int>> adjList) {
    visited[node] = true;

    for(auto neighbour : adjList[node]) {
        if(!visited[neighbour])
            topoSort(neighbour, visited, s, adjList);
    }
}