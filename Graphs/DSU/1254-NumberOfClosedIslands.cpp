/*
    Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top,
    right, bottom) surrounded by 1s. Return the number of closed islands.

    Example 1:
    Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
    Output: 2
    Explanation:  Islands in gray are closed because they are completely surrounded by water (group of 1s).
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

        for(int i=0; i<n+1; i++)
            parent[i] = i;
    }

    int findUltParent(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = findUltParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ultU = findUltParent(u);
        int ultV = findUltParent(v);

        if(ultU == ultV)
            return;

        if(size[ultU] < size[ultV]) {
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
        } else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
        }
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        DSU ds(n * m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1)
                    continue;

                int node = i * m + j;

                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if(grid[nx][ny] == 0) {
                            int newNode = nx * m + ny;
                            ds.unionBySize(node, newNode);
                        }
                    }
                }
            }
        }

        set<int> openComponents;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1)
                    continue;

                // need to remove 0's at boundary;
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    int node = i * m + j;
                    openComponents.insert(ds.findUltParent(node));
                }
            }
        }

        set<int> components;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    int node = i * m + j;
                    components.insert(ds.findUltParent(node));
                }
            }
        }

        return components.size() - openComponents.size();
    }
};