/*
    You are given a 2D integer array towers, where towers[i] = [xi, yi, qi] represents the coordinates (xi, yi) and quality factor qi of the ith tower. You are also given an 
    integer array center = [cx, cy​​​​​​​] representing your location, & an integer radius. A tower is reachable if its Manhattan distance from center is less than or equal to radius.
    Among all reachable towers: Return the coordinates of the tower with the maximum quality factor. If there is a tie, return the tower with the lexicographically smallest 
    coordinate. If no tower is reachable, return [-1, -1]. The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
    A coordinate [xi, yi] is lexicographically smaller than [xj, yj] if xi < xj, or xi == xj and yi < yj. |x| denotes the absolute value of x.

    Example 1:
    Input: towers = [[1,2,5], [2,1,7], [3,1,9]], center = [1,1], radius = 2
    Output: [3,1]
    Explanation: Tower [1, 2, 5]: Manhattan distance = |1 - 1| + |2 - 1| = 1, reachable. Tower [2, 1, 7]: Manhattan distance = |2 - 1| + |1 - 1| = 1, reachable.
    Tower [3, 1, 9]: Manhattan distance = |3 - 1| + |1 - 1| = 2, reachable. All towers are reachable. The maximum quality factor is 9, which corresponds to tower [3, 1].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int quality = -1;
        int dx = -1;
        int dy = -1;
        int cx = center[0];
        int cy = center[1];

        for(auto i : towers) {
            int x = i[0];
            int y = i[1];
            int q = i[2];

            if(abs(cx - x) + abs(cy - y) <= radius) {
                if(q > quality) {
                    dx = x;
                    dy = y;
                    quality = q;
                } else if(q == quality) {
                    if(dx > x || (dx == x && dy > y)) {
                        dx = x;
                        dy = y;
                    }
                }
            }
        }

        return {dx, dy};
    }
};