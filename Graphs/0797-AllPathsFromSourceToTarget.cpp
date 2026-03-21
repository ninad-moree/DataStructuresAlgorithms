/*
    Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
    The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

    Example 1:
    Input: graph = [[1,2],[3],[3],[]]
    Output: [[0,1,3],[0,2,3]]
    Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, int dest, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path, vector<vector<int>>& ans) {
        if(src == dest) {
            path.push_back(dest);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        vis[src] = true;
        path.push_back(src);

        for(auto node : graph[src]) {
            if(!vis[node])
                dfs(node, dest, graph, vis, path, ans);
        }

        path.pop_back();
        vis[src] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> ans;
        vector<int> vis(n, false);

        dfs(0, n-1, graph, vis, path, ans);

        return ans;
    }
};