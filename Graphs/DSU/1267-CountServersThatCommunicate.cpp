/*
    You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two 
    servers are said to communicate if they are on the same row or on the same column. Return the number of servers that communicate with any other server.

    Example 1:
    Input: grid = [[1,0],[0,1]]
    Output: 0
    Explanation: No servers can communicate with others.
*/

#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> size;
    vector<int> parent;

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);

        for(int i=0; i<n; i++)
            parent[i] = i;
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
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU ds(n*m);

        vector<int> rowFirst(n, -1);  // first server node seen in each row
        vector<int> colFirst(m, -1);  // first server node seen in each column

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;

                int node = i * m + j;

                if (rowFirst[i] == -1)
                    rowFirst[i] = node;
                else
                    ds.unionBySize(node, rowFirst[i]);

                if (colFirst[j] == -1)
                    colFirst[j] = node;
                else
                    ds.unionBySize(node, colFirst[j]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;

                int node = i * m + j;
                if (ds.size[ds.findUltPar(node)] > 1)
                    count++;
            }
        }

        return count;
    }
};