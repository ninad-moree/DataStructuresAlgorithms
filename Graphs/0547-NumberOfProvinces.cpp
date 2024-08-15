/*
    There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly 
    with city c, then city a is connected indirectly with city c. A province is a group of directly or indirectly connected cities and no other cities
    outside of the group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly 
    connected, and isConnected[i][j] = 0 otherwise. Return the total number of provinces.

    Example 1:
    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        for(auto i : adj[node]) {
            if(!visited[i])
                dfs(i, visited, adj);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);

        int ans = 0;

        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                ans++;
                dfs(i, visited, adj);
            }
        } 

        return ans;
    }
};