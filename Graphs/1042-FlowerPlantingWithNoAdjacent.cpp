/*
    You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want
    to plant one of 4 types of flowers. All gardens have at most 3 paths coming into or leaving it. Your task is to choose a flower type for each garden such that, for any two 
    gardens connected by a path, they have different types of flowers. Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th 
    garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

    Example 1:
    Input: n = 3, paths = [[1,2],[2,3],[3,1]]
    Output: [1,2,3]
    Explanation: Gardens 1 and 2 have different types. Gardens 2 and 3 have different types. Gardens 3 and 1 have different types.
    Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& flower) {
        queue<int> q;
        q.push(node);

        vis[node] = 1;
        flower[node] = 1;

        while(!q.empty()) {
            int n = q.front();
            q.pop();

            for(auto neigh : adj[node]) {
                if(!vis[neigh]) {
                    vector<int> col(5, 0);
                    for(auto i : adj[neigh])
                        col[flower[i]] = 1;

                    for(int i=1; i<5; i++) {
                        if(col[i] == 0) {
                            flower[neigh] = i;
                            break;
                        }
                    }

                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        vector<int> flower(n);
        vector<int> vis(n);

        for(auto i : paths) {
            int x = i[0] - 1;
            int y = i[1] - 1;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) 
                bfs(i, adj, vis, flower);
        }

        return flower;
    }
};