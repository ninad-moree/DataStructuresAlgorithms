/*
    You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally
    or vertically). The total value of an island is the sum of the values of all cells in the island. Return the number of islands with a total value divisible by k.

    Example 1:
    Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
    Output: 2
    Explanation: The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
*/

#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> size;
    vector<int> parent;

    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUltPar(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findUltPar(parent[u]);
    }

    void unionBySize(int u, int v, vector<long long>& cellValue) {
        int ultU = findUltPar(u);
        int ultV = findUltPar(v);

        if(ultU == ultV)
            return;

        if(size[ultU] < size[ultV]) {
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
            cellValue[ultV] += cellValue[ultU];
        } else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
            cellValue[ultU] += cellValue[ultV];
        }
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<long long> cellValue(n * m);

        DSU ds(n * m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int node = i * m + j;
                int val = grid[i][j];

                cellValue[node] = val;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0)
                    continue;

                int node = i * m + j;

                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0) {
                        int newNode = nx * m + ny;
                        ds.unionBySize(node, newNode, cellValue);
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0)
                    continue;

                int node = i * m + j;

                if(ds.findUltPar(node) == node) {
                    long long val = cellValue[node];

                    if(val % k == 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};