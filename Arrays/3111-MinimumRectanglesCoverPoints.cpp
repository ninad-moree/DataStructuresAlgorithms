/*
    You are given a 2D integer array points, where points[i] = [xi, yi]. You are also given an integer w. Your task is to cover all the given 
    points with rectangles.
    Each rectangle has its lower end at some point (x1, 0) and its upper end at some point (x2, y2), where x1 <= x2, y2 >= 0, and the condition 
    x2 - x1 <= w must be satisfied for each rectangle.
    A point is considered covered by a rectangle if it lies within or on the boundary of the rectangle.
    Return an integer denoting the minimum number of rectangles needed so that each point is covered by at least one rectangle.

    Example 1:
    Input: points = [[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]], w = 1
    Output: 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int n = points.size();
        int ans = 0;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int maxY = points[i][1];

            
            while (j < n && points[j][0] - points[i][0] <= w) {
                maxY = max(maxY, points[j][1]);
                j++;
            }
            i = j;

            ans++;
        }

        return ans;
    }
};