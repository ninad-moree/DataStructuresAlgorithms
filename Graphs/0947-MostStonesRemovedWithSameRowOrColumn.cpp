/*
    On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone. A stone can be removed if it shares either the same row
    or the same column as another stone that has not been removed. Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return 
    the largest possible number of stones that can be removed.

    Example 1:
    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    Output: 5
    Explanation: One way to remove 5 stones is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,1]. 2. Remove stone [2,1] because it shares the same column as [0,1].
    3. Remove stone [1,2] because it shares the same row as [1,0]. 4. Remove stone [1,0] because it shares the same column as [0,0].
    5. Remove stone [0,1] because it shares the same row as [0,0]. Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // finding the last row and col where the stone is placed
        for(auto i : stones) {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        
        // Connecting the components with each other
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for(auto i : stones) {
            int nodeRow = i[0];
            int nodeCol = i[1] + maxRow + 1;  // normalising the col node to avoid collision with row node
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto i : stoneNodes) {
            if(ds.findUParent(i.first) == i.first)
                cnt++;
        }

        return n - cnt;
    }
};