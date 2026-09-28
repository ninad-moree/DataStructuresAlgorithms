/*
    You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where 
    entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at. In one step, you can move one cell up, down, left, or right. You
    cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that 
    is at the border of the maze. The entrance does not count as an exit. Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no 
    such path exists.

    Example 1:
    Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
    Output: 1
    Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3]. Initially, you are at the entrance cell [1,2]. - You can reach [1,0] by moving 2 steps left.
    - You can reach [0,2] by moving 1 step up. It is impossible to reach [2,3] from the entrance. Thus, the nearest exit is [0,2], which is 1 step away.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        int ans = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(!(x == entrance[0] && y == entrance[1])){
                    if(x == 0 || x == n-1 || y == 0 || y == m-1)
                        return ans;
                }

                for(int i=0; i<4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && maze[nx][ny] == '.') {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};