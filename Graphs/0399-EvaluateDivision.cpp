/*
    You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation 
    Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable. You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where
    you must find the answer for Cj / Dj = ?. Return the answers to all queries. If a single answer cannot be determined, return -1.0. Note: The input is always valid. You may 
    assume that evaluating the queries will not result in division by zero and that there is no contradiction. Note: The variables that do not occur in the list of equations are
    undefined, so the answer cannot be determined for them.

    Example 1:
    Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    Explanation: 
    Given: a / b = 2.0, b / c = 3.0
    queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
    return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
    note: x is undefined => -1.0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& adj, unordered_set<string>& vis, double& ans, double temp) {
        if(vis.find(node) != vis.end())
            return;

        vis.insert(node);
        if(node == dest) {
            ans = temp;
            return;
        }

        for(auto i : adj[node])
            dfs(i.first, dest, adj, vis, ans, temp * i.second); // temp * i.second => a/b = 2, b/c = 3 => a/c = a/b * b/c = 2 * 3
    }

    unordered_map<string, unordered_map<string, double>> graph(vector<vector<string>>& equations, const vector<double>& values) {
       unordered_map<string, unordered_map<string, double>> adj;

        for(int i=0; i<values.size(); i++) {
            string num = equations[i][0];
            string den = equations[i][1];
            double value = values[i];

            adj[num][den] = value;
            adj[den][num] = 1.0 / value;
        }

       return adj;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj = graph(equations, values);
        vector<double> res;

        for(int i=0; i<queries.size(); i++) {
            string num = queries[i][0];
            string den = queries[i][1];

            if(adj.find(num) == adj.end() || adj.find(den) == adj.end())
                res.push_back(-1.0);
            else {
                unordered_set<string> vis;
                double ans = -1.0;
                double temp = 1.0;
                dfs(num, den, adj, vis, ans, temp);
                res.push_back(ans);
            }
        }

        return res;
    }
};