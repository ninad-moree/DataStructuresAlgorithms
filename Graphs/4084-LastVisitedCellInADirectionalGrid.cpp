/*
    You are given an m x n matrix grid where each cell contains one of the following characters: 'L': move one cell left. 'R': move one cell right. 'U': move one cell up.
    'D': move one cell down. You start at cell (0, 0), which is considered visited. At each step, move to the cell indicated by the character in your current cell. The process 
    ends if the indicated move would either leave the grid or enter a cell that has already been visited. In either case, the move is not made.
    Return an integer array [r, c] representing the row and column indices of the last visited cell. The indices are 0-based.

    Example 1:
    Input: grid = [["R","D"],["U","L"]]
    Output: [1,0]
    Explanation: Start at cell (0, 0), which contains 'R', so move right to (0, 1). At cell (0, 1), the character is 'D', so move down to (1, 1).
    At cell (1, 1), the character is 'L', so move left to (1, 0). At cell (1, 0), the character is 'U', which indicates moving to (0, 0). However, (0, 0) has already been
    visited, so this move is not made. Therefore, the process ends at the last visited cell (1, 0), so the answer is [1, 0].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));

        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            char ch = grid[x][y];

            int nx, ny;

            if(ch == 'L') {
                nx = x ;
                ny = y - 1;
            } else if(ch == 'R') {
                nx = x;
                ny = y + 1;
            } else if(ch == 'U') {
                nx = x - 1;
                ny = y;
            } else {
                nx = x + 1;
                ny = y;
            }

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) 
                return {x, y};

            q.push({nx, ny});
            vis[nx][ny] = 1;
        }

        return {-1, -1};
    }
};