/*
    You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes 
    that there exists an undirected edge connecting nodes ai and bi. Return the number of pairs of different nodes that are unreachable from each other.

    Example 1:
    Input: n = 3, edges = [[0,1],[0,2],[1,2]]
    Output: 0
    Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> size, parent;

    public:
    DisjointSet(int n) {
        size.resize(n+1, 1); 
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findUParent(u); 
        int ultimateParentV = findUParent(v); 

        if(ultimateParentU == ultimateParentV)
            return;

        if(size[ultimateParentU] < size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } 
        else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for(auto e : edges) 
            ds.unionBySize(e[0], e[1]);
        
        unordered_map<int, long long> compSize;

        for(int i = 0; i < n; i++) {
            int parent = ds.findUParent(i);
            compSize[parent]++;
        }

        long long ans = 0;
        long long remaining = n;

        for(auto &it : compSize) {
            long long sz = it.second;
            ans += sz * (remaining - sz);
            remaining -= sz;
        }

        return ans;
    }
};