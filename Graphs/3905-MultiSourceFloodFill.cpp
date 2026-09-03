/*
    You are given two integers n and m representing the number of rows and columns of a grid, respectively. You are also given a 2D integer array sources, where sources[i] = 
    [ri, ci, color​​​​​​​i] indicates that the cell (ri, ci) is initially colored with colori. All other cells are initially uncolored and represented as 0. At each time step, every 
    currently colored cell spreads its color to all adjacent uncolored cells in the four directions: up, down, left, and right. All spreads happen simultaneously. If multiple 
    colors reach the same uncolored cell at the same time step, the cell takes the color with the maximum value. The process continues until no more cells can be colored.
    Return a 2D integer array representing the final state of the grid, where each cell contains its final color.

    Example 1:
    Input: n = 3, m = 3, sources = [[0,0,1],[2,2,2]]
    Output: [[1,1,2],[1,2,2],[2,2,2]]
    Explanation: The grid at each time step is as follows:
    At time step 2, cells (0, 2), (1, 1), and (2, 0) are reached by both colors, so they are assigned color 2 as it has the maximum value among them.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // {distance, color, x, y}
        priority_queue< tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(m));

        for(auto i : sources) {
            int x = i[0];
            int y = i[1];
            int c = i[2];

            grid[x][y] = c;
            pq.push({0, -c, x, y}); // larger color first for the same distance, therefore -c.
        }

        while(!pq.empty()) {
            tuple<int, int, int, int> top = pq.top();
            pq.pop();

            int dist = get<0>(top);
            int negCol = get<1>(top);
            int x = get<2>(top);
            int y = get<3>(top);

            int col = -negCol;

            if(vis[x][y])
                continue;

            vis[x][y] = 1;
            grid[x][y] = col;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (vis[nx][ny])
                    continue;

                pq.push({dist + 1, -col, nx, ny});
            }
        }

        return grid;
    }
};