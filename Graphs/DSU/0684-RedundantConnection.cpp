/*
    In this problem, a tree is an undirected graph that is connected and has no cycles. You are given a graph that started as a tree with n nodes labeled from 1 to n, with one 
    additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of 
    length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph. Return an edge that can be removed so that the resulting graph is a 
    tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

    Example 1:
    Input: edges = [[1,2],[1,3],[2,3]]
    Output: [2,3]
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> size, parent;

    public:
    DisjointSet(int n) {
        size.resize(n+1, 1); // For both 0-based and 1-based indexing
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); // Path Compression
    }

    bool unionBySize(int u, int v) {
        int ultimateParentU = findUParent(u); // ultimate parent of u
        int ultimateParentV = findUParent(v); // ultimate parent of v

        if(ultimateParentU == ultimateParentV)
            return 0;

        if(size[ultimateParentU] < size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }

        return 1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet ds(n);
        for(auto i : edges) {
            if(!ds.unionBySize(i[0]-1, i[1]-1))
                return i;
        }

        return {};
    }
};