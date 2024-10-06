/*
    You are maintaining a project that has n methods numbered from 0 to n - 1.
    You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
    There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we 
    aim to remove them. A group of methods can only be removed if no method outside the group invokes any methods within it. Return an array containing 
    all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the
    suspicious methods, none should be removed.

    Example 1:
    Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
    Output: [0,1,2,3]
    Explanation:
    Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without 
    removing anything.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int n, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[n] = true;
        for(auto i : adj[n]) {
            if(!vis[i])
                dfs(i, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto i : invocations)
            adj[i[0]].push_back(i[1]);
        
        vector<bool> vis(n, false);
        dfs(k, adj, vis);

        bool isSus = true;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                for(auto j : adj[i]) {
                    if(vis[j])
                        isSus = false;
                }
            }
        }
        
        vector<int> ans;
        if(isSus) {
            for(int i=0; i<n; i++) {
                if(!vis[i])
                    ans.push_back(i);
            }
        } else {
            for(int i=0; i<n; i++) 
                ans.push_back(i);
        }

        return ans;
    }
};