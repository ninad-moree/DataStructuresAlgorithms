/*
    Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
    Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, 
    from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


    Example 1:
    Input:
    V = 5, E = 4
    adj = {{1,2,3},{},{4},{},{}}

    Output: 
    0 1 2 3 4
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> arr;
        
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            arr.push_back(front);
            
            for(auto i : adj[front]) {

                    if(!visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                
            }
        }
        
        return arr;
    }
};