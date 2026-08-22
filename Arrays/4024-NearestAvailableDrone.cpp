/*
    You are given a 2D integer array drones, where drones[i] = [xi, yi, rangei] represents the x-coordinate, y-coordinate, and travel range of the ith drone. You are also given
    an integer array target = [tx, ty], representing the coordinates of the target. A drone drones[i] can reach the target if the Manhattan distance between its coordinates and
    the target coordinates is less than or equal to its rangei. Return the index of the reachable drone with the minimum Manhattan distance to the target. If there is a tie, 
    return the smallest index. If no drone can reach the target, return -1.

    Example 1:
    Input: drones = [[0,0,8],[2,2,9]], target = [3,4]
    Output: 1
    Explanation: The distance between drones[0] and target is |0 - 3| + |0 - 4| = 7, which is within its range of 8. The distance between drones[1] and target is |2 - 3| + 
    |2 - 4| = 3, which is within its range of 9. Since drones[1] is the nearest drone, the answer is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int tx = target[0];
        int ty = target[1];

        int minDis = INT_MAX;
        int ans = -1;

        for(int i=0; i<drones.size(); i++) {
            int dx = drones[i][0];
            int dy = drones[i][1];
            int range = drones[i][2];

            int dist = abs(dx - tx) + abs(dy - ty);

            if(dist <= range) {
                if(dist < minDis || (dist == minDis && i < ans)) {
                    minDis = dist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};