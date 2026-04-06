/*
    A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to 
    execute. There are only three possible types of instructions the robot can receive:
    -2: Turn left 90 degrees. -1: Turn right 90 degrees. 1 <= k <= 9: Move forward k units, one unit at a time.
    Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location 
    (on the block adjacent to the obstacle) and move onto the next command. Return the maximum squared Euclidean distance that the robot reaches at any point in its path 
    (i.e. if the distance is 5, return 25).
    Note: There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to 
    (0, 0) due to the obstacle. North means +Y direction. East means +X direction. South means -Y direction. West means -X direction.
    
    Example 1:
    Input: commands = [4,-1,3], obstacles = []
    Output: 25
    Explanation: The robot starts at (0, 0): Move north 4 units to (0, 4). Turn right. Move east 3 units to (3, 4).
    The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (const auto& obs : obstacles) 
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));

        const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0; // 0: North, 1: East, 2: South, 3: West
        int x = 0, y = 0;
        int maxDistSquared = 0;

        for (const auto& command : commands) {
            if (command == -2) 
                directionIndex = (directionIndex + 3) % 4;
            else if (command == -1) 
                directionIndex = (directionIndex + 1) % 4;
            else if (command >= 1 && command <= 9) {
                int dx = directions[directionIndex].first;
                int dy = directions[directionIndex].second;

                for (int i = 0; i < command; ++i) {
                    x += dx;
                    y += dy;
                    string pos = to_string(x) + "," + to_string(y);
                    if (obstacleSet.find(pos) == obstacleSet.end()) {
                        int distSquared = x * x + y * y;
                        maxDistSquared = max(maxDistSquared, distSquared);
                    } else {
                        x -= dx;
                        y -= dy;
                        break;
                    }
                }
            }
        }

        return maxDistSquared;
    }
};