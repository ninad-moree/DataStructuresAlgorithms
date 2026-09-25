/*
    You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents: A land cell if grid[r][c] = 0, or water cell containing grid[r][c] fish, if grid[r][c] > 0.
    A fisher can start at any water cell (r, c) and can do the following operations any number of times: Catch all the fish at cell (r, c), or
    Move to any adjacent water cell. Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
    An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

    Example 1:
    Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
    Output: 7
    Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
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

    void unionBySize(int u, int v, vector<int>& fishCnt) {
        int ultU = findUltParent(u);
        int ultV = findUltParent(v);

        if(ultU == ultV)
            return;

        if(size[ultU] < size[ultV]) {
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
            fishCnt[ultV] += fishCnt[ultU];
        } else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
            fishCnt[ultU] += fishCnt[ultV];
        }
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU ds(n * m);

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        vector<int> fishCnt(n * m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int node = i * m + j;

                fishCnt[node] = grid[i][j];
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

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if(grid[nx][ny] != 0) {
                            int newNode = nx * m + ny;
                            ds.unionBySize(node, newNode, fishCnt);
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int i=0; i<n*m; i++) {
            if(ds.findUltParent(i) == i)
                ans = max(ans, fishCnt[i]);
        }

        return ans;
    }
};