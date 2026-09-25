/*
    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s.

    Example 1:
    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> size, parent;

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
		int dc[] = {0, 1, 0, -1};

        // Calculate each component
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0)
                    continue;

                for(int i=0; i<4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Convert 0 -> 1 to merge
        int ans = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1)
                    continue;

                set<int> components;

                for(int i=0; i<4; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                        if(grid[newRow][newCol] == 1) 
                            components.insert(ds.findUParent(newRow * n + newCol));
                    }
                }

                int sizeT = 0;
                for(auto i : components)
                    sizeT += ds.size[i];
                
                ans = max(ans, sizeT + 1);
            }
        }

        for(int cell=0; cell<n*n; cell++) 
            ans = max(ans, ds.size[ds.findUParent(cell)]);

        return ans;
    }
};