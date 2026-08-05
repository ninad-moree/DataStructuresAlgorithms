/*
    You are maintaining a project that has n methods numbered from 0 to n - 1. You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = 
    [ai, bi] indicates that method ai invokes method bi. There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are 
    considered suspicious and we  aim to remove them. A group of methods can only be removed if no method outside the group invokes any methods within it. Return an array 
    containing  all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious 
    methods, none should be removed.

    Example 1:
    Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
    Output: [0,1,2,3]
    Explanation: Method 2 & method 1 are suspicious, but they are directly invoked by methods 3 & 0, which are not suspicious. We return all elements without removing anything.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;

        for(auto n : adj[src]) {
            if(!vis[n]) 
                dfs(n, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> vis(n); // 1 means method i is "suspicious" (reachable from k)
        vector<vector<int>> adj(n);

        for(auto i : invocations) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
        }

        dfs(k, adj, vis);

        // Check if is there any edge from a NON-suspicious method into a suspicious method? 
        // If so, removing the suspicious set is unsafe (some "safe" method still calls into it), so we
        // must keep everything -> return all methods.
        for(auto i : invocations) {
            int u = i[0];
            int v = i[1];

            if(!vis[u] && vis[v]) {
                vector<int> all(n);

                for(int j=0; j<n; j++)
                    all[j] = j;
                
                return all;
            }
        }

        // Safe to remove all suspicious methods.
        // Return every method that is NOT suspicious (vis[i] == 0)
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(!vis[i])
                ans.push_back(i);
        }

        return ans;
    } 
};