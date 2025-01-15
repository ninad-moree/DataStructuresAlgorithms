#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int nodes;
    vector<vector<int>> adjList ;

    Graph(int n) {
        nodes = n;
        adjList = {};
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void  DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout<<v<<" ";

        for(int i : adjList[v]) {
            if(!visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int startNode) {
        vector<bool> visited(nodes, false);
        cout<<"DFS:"<<endl;
        DFSUtil(startNode, visited);
        cout<<endl;
    }
};