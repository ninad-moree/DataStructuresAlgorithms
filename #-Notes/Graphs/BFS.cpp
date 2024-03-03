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

    void BFS(int startNode) {
        vector<bool> visited(nodes , false); 
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for(int i : adjList[curr]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
    }
};