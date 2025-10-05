/*
    There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top 
    edges, and the Atlantic Ocean touches the island's right and bottom edges. The island is partitioned into a grid of square cells. You are given an
    m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c). The island receives a lot 
    of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or 
    equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean. Return a 2D list of grid coordinates result 
    where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

    Example 1:
    Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
    [0,4]: [0,4] -> Pacific Ocean  [0,4] -> Atlantic Ocean
    [1,3]: [1,3] -> [0,3] -> Pacific Ocean  [1,3] -> [1,4] -> Atlantic Ocean
    [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean  [1,4] -> Atlantic Ocean
    [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean  [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
    [3,0]: [3,0] -> Pacific Ocean  [3,0] -> [4,0] -> Atlantic Ocean
    [3,1]: [3,1] -> [3,0] -> Pacific Ocean  [3,1] -> [4,1] -> Atlantic Ocean
    [4,0]: [4,0] -> Pacific Ocean  [4,0] -> Atlantic Ocean
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkVisited(string ocean, pair<int, int> p) {
        if (ocean == "atlantic")
            return p.second == 1;
        return p.first == 1;
    }

    void bfs(string ocean, vector<vector<int>>& ht, vector<vector<pair<int, int>>>& visited, queue<pair<int, int>>& q, vector<pair<int, int>> dir, int n, int m) {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto i : dir) {
                int newX = x + i.first;
                int newY = y + i.second;

                if (newX < 0 || newX >= n || newY < 0 || newY >= m || ht[newX][newY] < ht[x][y] || checkVisited(ocean, visited[newX][newY])) 
                    continue;

                if(ocean == "atlantic")
                    visited[newX][newY].second = 1;
                else
                    visited[newX][newY].first = 1;

                q.push({newX, newY});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<pair<int, int>>> visited(n, vector<pair<int, int>> (m, {0, 0}));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            visited[n-1][i].second = 1;
            q.push({n-1, i});
        }
        for(int i=0; i<n; i++){
            visited[i][m-1].second = 1;
            q.push({i, m-1});
        } 

        bfs("atlantic" ,heights, visited, q, directions, n, m);

        for(int i=0; i<n; i++){
            visited[i][0].first = 1;
            q.push({i, 0});
        } 
        for(int i=0; i<m; i++){
            visited[0][i].first = 1;
            q.push({0, i});
        }

        bfs("pacific", heights, visited, q, directions, n, m);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pair<int, int> it = visited[i][j];
                if(it.first && it.second)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};