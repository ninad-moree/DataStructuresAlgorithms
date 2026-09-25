/*
    You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth
    column. Each cell is one of the following: '.' representing an empty cell. '#' representing an obstacle. An uppercase letter ('A'-'Z') representing a teleportation portal.
    You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, 
    left, right) as long as the destination cell is within the grid and isn't an obstacle. If you step on a cell containing a portal letter and you haven't used that  portal 
    letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation doesn't count as a move, but each portal letter can be
    used at most once during your journey. Return the minimum number of moves required to reach the bottom-right cell. If it isn't possible to reach the destination, return -1.

    Example 1:
    Input: matrix = ["A..",".A.","..."]
    Output: 2
    Explanation: Before the first move, teleport from (0, 0) to (1, 1). In the first move, move from (1, 1) to (1, 2). In the second move, move from (1, 2) to (2, 2).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> mp;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] != '.' && matrix[i][j] != '#')
                    mp[matrix[i][j]].push_back({i, j});
            }
        }

        if(matrix[n-1][m-1] == '#' || matrix[0][0] == '#')
            return -1;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        // {dist, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        unordered_set<char> used;

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()) {
            tuple<int, int, int> curr = pq.top();
            pq.pop();
            
            int d = get<0>(curr);
            int x = get<1>(curr);
            int y = get<2>(curr);
            
            if(d > dist[x][y])
                continue;

            if(x == n-1 && y == m-1)
                return d;
            
            // check portal
            if(isupper(matrix[x][y]) && used.find(matrix[x][y]) == used.end()) {
                used.insert(matrix[x][y]);

                for(auto i : mp[matrix[x][y]]) {
                    int nx = i.first;
                    int ny = i.second;

                    if(d < dist[nx][ny]) {
                        dist[nx][ny] = d;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }

            // check neighbors
            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != '#') {
                    if(dist[nx][ny] > 1 + d) {
                        dist[nx][ny] = 1 + d;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};