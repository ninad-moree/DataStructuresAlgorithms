/*
    A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list 
    of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
    vertically. You may assume all four edges of the grid are all surrounded by water.

    Example:
    Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
    Output: [1,1,2,3]
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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DisjointSet ds(n * m);
	vector<vector<int>> vis(n, vector<int>(m, 0));
	int cnt = 0;
	vector<int> ans;

	for(int i=0; i<q.size(); i++) {
		int row = q[i][0];
		int col = q[i][1];

		if(vis[row][col] == 1) {
			ans.push_back(cnt);
			continue;
		}

		vis[row][col] = 1;
		cnt++;
		int dr[] = {-1, 0, 1, 0};
		int dc[] = {0, 1, 0, -1};

		for(int j=0; j<4; j++) {
			int newRow = row + dr[j];
			int newCol = col + dc[j];

			if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
				if(vis[newRow][newCol] == 1) {
					int node = row * m + col;
					int adjNode = newRow * m + newCol;
					if(ds.findUParent(node) != ds.findUParent(adjNode)) {
						cnt--;
						ds.unionBySize(node, adjNode);
					}
				}
			}
		}

		ans.push_back(cnt);
	}

	return ans;
}