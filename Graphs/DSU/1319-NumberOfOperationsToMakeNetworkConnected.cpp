/*
    There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] 
    represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
    You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place 
    them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order 
    to make all the computers connected. If it is not possible, return -1.

    Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1, 0); // For both 0-based and 1-based indexing
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]); // Path Compression
    }

    void unionBySize(int u, int v) {
        int ultimateParentU = findUParent(u); // ultimate parent of u
        int ultimateParentV = findUParent(v); // ultimate parent of v

        if(ultimateParentU == ultimateParentV)
            return;

        if(size[ultimateParentU] < size[ultimateParentV]) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;

        for(auto i : connections) {
            int u = i[0];
            int v = i[1];

            if(ds.findUParent(u) == ds.findUParent(v))
                extraEdges++;
            else
                ds.unionBySize(u, v);
        }

        int components = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i)
                components++;
        }

        int ans = components - 1;

        if(extraEdges >= ans)
            return ans;
        return -1;
    }
};
