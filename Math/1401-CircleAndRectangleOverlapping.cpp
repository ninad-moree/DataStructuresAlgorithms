/*
    You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the 
    bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle. Return true if the circle and rectangle are overlapped otherwise return false.
    In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

    Example 1:
    Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
    Output: true
    Explanation: Circle and rectangle share the point (1,0).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist = 0;

        if (xCenter < x1 || xCenter > x2) 
            dist += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
        
        if (yCenter < y1 || yCenter > y2) 
            dist += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));
        
        return dist <= radius * radius;
    }
};   