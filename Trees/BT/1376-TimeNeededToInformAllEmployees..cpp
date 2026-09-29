/*
    A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID. Each employee has one direct manager given in 
    the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree
    structure. The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their 
    subordinates, and so on until all employees know about the urgent news. The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After 
    informTime[i] minutes, all his direct subordinates can start spreading the news). Return the number of minutes needed to inform all the employees about the urgent news.

    Example 1:
    Input: n = 1, headID = 0, manager = [-1], informTime = [0]
    Output: 0
    Explanation: The head of the company is the only employee in the company.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxTime = 0;

        for(auto i : adj[node]) 
            maxTime = max(maxTime, dfs(i, adj, informTime));
        
        return informTime[node] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for(int i=0; i<manager.size(); i++) {
            int u = i;
            int v = manager[i];

            if(v != -1)
                adj[v].push_back(u);
        }

        return dfs(headID, adj, informTime);
    }
};