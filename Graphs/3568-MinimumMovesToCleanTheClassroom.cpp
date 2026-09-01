/*
    You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
    'S': Starting position of the student 'L': Litter that must be collected (once collected, the cell becomes empty)
    'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
    'X': Obstacle the student cannot pass through '.': Empty space
    You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.
    Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', 
    which resets the energy to its maximum capacity energy. Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.

    Example 1:
    Input: classroom = ["S.", "XL"], energy = 2
    Output: 2
    Explanation: The student starts at cell (0, 0) with 2 units of energy. Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
    A valid sequence of moves to collect all litter is as follows: Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
    Move 2: From (0, 1) → (1, 1) to collect the litter 'L'. The student collects all the litter using 2 moves. Thus, the output is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int sx = 0, sy = 0;

        // Store each L position with an index
        vector<vector<int>> litter(n, vector<int>(m, -1));
        int litterCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') 
                    litter[i][j] = litterCount++;
                
            }
        }

        int targetMask = (1 << litterCount) - 1;

        // {x, y, remainingEnergy, collectedMask}
        queue<tuple<int, int, int, int>> q;

        // vis[x][y][mask] = maximum energy seen at this state
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(1 << litterCount, -1)));

        q.push({sx, sy, energy, 0});
        vis[sx][sy][0] = energy;

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                tuple<int, int, int, int> curr = q.front();
                q.pop();

                int x = get<0>(curr);
                int y = get<1>(curr);
                int e = get<2>(curr);
                int mask = get<3>(curr);

                // If all L cells are collected
                if (mask == targetMask) 
                    return moves;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    if (e == 0)
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    if (classroom[nx][ny] == 'R') 
                        newEnergy = energy;

                    if (classroom[nx][ny] == 'L') 
                        newMask |= (1 << litter[nx][ny]);

                    // We only need to revisit if we have more energy
                    // for the same position + collected litter
                    if (vis[nx][ny][newMask] >= newEnergy)
                        continue;

                    vis[nx][ny][newMask] = newEnergy;
                    q.push({nx, ny, newEnergy, newMask});
                }
            }

            moves++;
        }

        return -1;
    }
};