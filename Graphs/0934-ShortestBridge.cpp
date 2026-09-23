/*
    You are given an n x n binary matrix grid where 1 represents land and 0 represents water. An island is a 4-directionally connected group of 1's not connected to any other 
    1's. There are exactly two islands in grid. You may change 0's to 1's to connect the two islands to form one island. Return the smallest number of 0's you must flip to 
    connect the two islands.

    Example 1:
    Input: grid = [[0,1],[1,0]]
    Output: 1
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
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointUnionSet ds(n * n);

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // indetify the 2 islands
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) // Skip of cell is 0
                    continue;

                int node = i * n + j;

                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if(grid[nx][ny] == 1) {
                            int newNode = nx * n + ny;
                            ds.unionBySize(node, newNode);
                        }
                    }
                }
            }
        }

        int parent1 = -1;
        int parent2 = -1;

        // identify parent of 2 islands
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int node = i * n + j;
                    int parent = ds.findUltPar(node);

                    if(parent1 == -1)
                        parent1 = parent;
                    else if(parent != parent1) {
                        parent2 = parent;
                        break;
                    }
                }
            }
        }

        queue<pair<pair<int, int>, int>> q; // {{x, y}, distance from par1}
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // push all cells of island 1 into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int node = i * n + j;

                    if(ds.findUltPar(node) == parent1) {
                        q.push({{i, j}, 0});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        // BFS through water
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                // Reached island 2
                if(grid[nx][ny] == 1) {
                    int node = nx * n + ny;

                    if(ds.findUltPar(node) == parent2)
                        return dist;
                }

                // Expand through water
                vis[nx][ny] = 1;
                q.push({{nx, ny}, dist + 1});
            }
        }

        return -1;
    }
};