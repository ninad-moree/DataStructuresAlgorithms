/*
    There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y). We start at the source = [sx, sy] square and want to reach the 
    target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi). Each move, we
    can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid. Return true if 
    and only if it is possible to reach the target square from the source square through a sequence of valid moves.

    Example 1:
    Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
    Output: false
    Explanation: The target square is inaccessible starting from the source square because we cannot move. We cannot move north or east because those squares are blocked.
    We cannot move south or west because we cannot go outside of the grid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(vector<int>& source, vector<int>& target, set<pair<int, int>>& blocked, int maxArea) {
        int sx = source[0];
        int sy = source[1];

        int tx = target[0];
        int ty = target[1];

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};

        queue<pair<int, int>> q;
        set<pair<int, int>> vis;

        q.push({sx, sy});
        vis.insert({sx, sy});

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == tx && y == ty)
                return true;

            if(vis.size() > maxArea)
                return true;

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < 1e6 && ny >= 0 && ny < 1e6 && !vis.count({nx, ny}) && !blocked.count({nx, ny})) {
                    q.push({nx, ny});
                    vis.insert({nx, ny});
                }
            }
        }

        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if(blocked.empty())
            return true;

        set<pair<int, int>> st;
        for(auto& cell : blocked)
            st.insert({cell[0], cell[1]});

        int b = blocked.size();
        int maxArea = b * (b - 1) / 2;

        return bfs(source, target, st, maxArea) && bfs(target, source, st, maxArea);
    }
};