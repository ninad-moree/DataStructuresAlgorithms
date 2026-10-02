/*
    You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix: 0 means the cell cannot be walked through.
    1 represents an empty cell that can be walked through. A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
    In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off. You 
    must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell). Starting from the point (0, 0), return 
    the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1. Note: The input is generated such that no two trees have the 
    same height, and there is at least one tree needs to be cut off.

    Example 1:
    Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
    Output: 6
    Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        int n = forest.size();
        int m = forest[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        q.push({sx, sy});
        vis[sx][sy] = 1;

        int steps = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == tx && y == ty)
                    return steps;

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && forest[nx][ny] != 0) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            steps++;
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();

        vector<pair<int, pair<int,int>>> trees; // {tree ht --> coordinate}

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j], {i, j}});
            }
        }

        sort(trees.begin(), trees.end());

        int steps = 0;
        int x = 0;
        int y = 0;

        // consider cells containing trees as node of a graph
        for(auto tree : trees) {
            int nx = tree.second.first;
            int ny = tree.second.second;

            int dist = bfs(forest, x, y, nx, ny);

            if(dist == -1)
                return -1;

            steps += dist;
            x = nx;
            y = ny;
        }

        return steps;
    }
};