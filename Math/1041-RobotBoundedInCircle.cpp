/*
    On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
    The north direction is the positive direction of the y-axis.
    The south direction is the negative direction of the y-axis.
    The east direction is the positive direction of the x-axis.
    The west direction is the negative direction of the x-axis.

    The robot can receive one of three instructions:
    "G": go straight 1 unit.
    "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
    "R": turn 90 degrees to the right (i.e., clockwise direction).

    Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

    Example 1:
    Input: instructions = "GGLLGG"
    Output: true
    Explanation: The robot is initially at (0, 0) facing the north direction.
    "G": move one step. Position: (0, 1). Direction: North.
    "G": move one step. Position: (0, 2). Direction: North.
    "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
    "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
    "G": move one step. Position: (0, 1). Direction: South.
    "G": move one step. Position: (0, 0). Direction: South.
    Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dx = 0, dy = 1;

        unordered_set<string> visited;
        visited.insert("0,0");

        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += dx;
                y += dy;
            } else if (instruction == 'L') {
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else if (instruction == 'R') {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
        }

        return (x == 0 && y == 0) || !(dx == 0 && dy == 1);
    }
};