/*
    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges
    of the grid are surrounded by water. The area of an island is the number of cells with a value 1 in the island. Return the maximum area of an island in grid. If there is no
    island, return 0.

    Example 1:
    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],
    [0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointUnionSet {
    public:
    vector<int> size;
    vector<int> par;

    DisjointUnionSet(int n) {
        size.resize(n+1, 1);
        par.resize(n+1);

        for(int i=0; i<=n; i++)
            par[i] = i;
    }

    int findUltPar(int node) {
        if(node == par[node])
            return node;
        return par[node] = findUltPar(par[node]);
    }

    void unionBySize(int u, int v) {
        int ultU = findUltPar(u);
        int ultV = findUltPar(v);

        if(ultU == ultV)
            return;

        if(size[ultU] < size[ultV]) {
            par[ultU] = ultV;
            size[ultV] += size[ultU];
        } else {
            par[ultV] = ultU;
            size[ultU] += size[ultV];
        }
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjointUnionSet ds(n * m); // each cell is a node; --> [0, 1, 2, 3,] --> for(2x2 matrix)

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) // Skip of cell is 0
                    continue;

                int node = i * m + j;

                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if(grid[nx][ny] == 1) {
                            int newNode = nx * m + ny;
                            ds.unionBySize(node, newNode);
                        }
                    }
                }
            }
        }

        int ans = 0;

        // Find largest component
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0)
                    continue;

                int node = i * m + j;
                int parent = ds.findUltPar(node);

                ans = max(ans, ds.size[parent]);
            }
        }

        return ans;
    }
};