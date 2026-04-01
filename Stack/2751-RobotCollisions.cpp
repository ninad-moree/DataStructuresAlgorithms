/*
    There are n 1-indexed robots, each having a position on a line, health, and movement direction. You are given 0-indexed integer arrays positions, healths, and a string 
    directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique. All robots start moving on the line simultaneously at the same speed 
    in their given directions. If two robots ever share the same position while moving, they will collide. If two robots collide, the robot with lower health is removed from the 
    line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both 
    removed from the line. Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 
    1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array. Return an array containing the health of the remaining robot
    (in the order they were given in the input), after no further collisions can occur. Note: The positions may be unsorted.

    Example 1:
    Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
    Output: [2,17,9,15,10]
    Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, 
    [2, 17, 9, 15, 10].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index) 
            indices[index] = index;

        sort(indices.begin(), indices.end(),[&](int lhs, int rhs) { 
            return positions[lhs] < positions[rhs]; 
        });

        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') 
                stack.push(currentIndex);
            else {
                while (!stack.empty() && healths[currentIndex] > 0) {
                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int index = 0; index < n; ++index) {
            if (healths[index] > 0) 
                result.push_back(healths[index]);
        }

        return result;
    }
};