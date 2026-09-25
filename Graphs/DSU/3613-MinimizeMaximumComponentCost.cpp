/*
    You are given an undirected connected graph with n nodes labeled from 0 to n - 1 and a 2D integer array edges where edges[i] = [ui, vi, wi] denotes an undirected edge 
    between node ui and node vi with weight wi, and an integer k. You are allowed to remove any number of edges from the graph such that the resulting graph has at most k 
    connected components. The cost of a component is defined as the maximum edge weight in that component. If a component has no edges, its cost is 0. Return the minimum 
    possible value of the maximum cost among all components after such removals.

    Example 1:
    Input: n = 5, edges = [[0,1,4],[1,2,3],[1,3,2],[3,4,6]], k = 2
    Output: 4
    Explanation: Remove the edge between nodes 3 and 4 (weight 6). The resulting components have costs of 0 and 4, so the overall maximum cost is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> size;
    vector<int> parent;
    int comp;

    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;

        comp = n;
    }

    int findUltPar(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findUltPar(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ultU = findUltPar(u);
        int ultV = findUltPar(v);

        if(ultU == ultV)
            return;

        if(size[ultU] < size[ultV]) {
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
        } else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
        }

        comp--;
    }

    int components() {
        return comp;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low = 0;
        int high = 0;

        for(auto i : edges)
            high = max(high, i[2]);

        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            DSU ds(n);

            for(auto e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if(w <= mid) 
                    ds.unionBySize(u, v);
            }

            int compo = ds.components();

            if(compo <= k) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};