/*
    There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph 
    where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i]. A node is a 
    terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node 
    (or another safe node). Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

    Example 1:
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]
    Explanation: The given graph is shown above. Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
    Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outD(graph.size(), 0);
        vector<vector<int>> revGraph(graph.size());

        for(int i=0; i<graph.size(); i++) {
            for(int j=0; j<graph[i].size(); j++) {
                revGraph[graph[i][j]].push_back(i);
                outD[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<outD.size(); i++) {
            if(outD[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int f = q.front();
            q.pop();

            ans.push_back(f);

            for(auto i : revGraph[f]) {
                outD[i]--;
                if(outD[i] == 0)
                    q.push(i);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};