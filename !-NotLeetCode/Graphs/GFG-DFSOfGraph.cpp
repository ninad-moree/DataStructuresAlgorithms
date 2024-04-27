/*
    You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
    Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


    Example 1:
    Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
    Output: 0 2 4 3 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> result;
        vector<bool> visited(V, false);

        dfsRecursive(0, visited, adj, result);

        return result;
    }
    
    void dfsRecursive(int node, vector<bool> &visited, vector<int> adj[], vector<int> &result) {
        visited[node] = true;
        result.push_back(node);

        for (int i : adj[node]) {
            if (!visited[i]) {
                dfsRecursive(i, visited, adj, result);
            }
        }
    }
};