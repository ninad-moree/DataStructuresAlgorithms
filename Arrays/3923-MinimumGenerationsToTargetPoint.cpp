/*
    You are given a 2D integer array points where points[i] = [xi, yi, zi] represents a point in 3D space, and an integer array target representing a target point. Define 
    generation 0 as the initial list of points. For each integer k >= 1, form generation k as follows: Consider every pair of two distinct points a = [x1, y1, z1] and b = 
    [x2, y2, z2] taken from all points produced in generations 0 through k - 1. For each such pair, compute c = [floor((x1 + x2) / 2), floor((y1 + y2)/2), floor((z1 + z2)/2)] 
    and collect every such c into a generation k. All points in the generation k are produced simultaneously from points in generations 0 through​​​​​​​ k - 1. After generation k is 
    formed, the points in the generation k are considered available for forming later generations. Return the smallest integer k such that the target appears in one of the 
    generations 0 through k. If the target is already in the initial points, return 0. If it is impossible to obtain the target, return -1. Notes:
    floor denotes rounding down to the nearest integer. "Two distinct points" means the two chosen points must have different (x, y, z) coordinates
    
    Example 1:
    Input: points = [[0,0,0],[6,6,6]], target = [3,3,3]
    Output: 1
    Explanation: Generation 0: The initial points = [[0, 0, 0], [6, 6, 6]]. The target = [3, 3, 3] does not exist in generation 0.
    Generation 1: For each pair of points in generation 0, we create new points. Using [0, 0, 0] and [6, 6, 6], we generate [3, 3, 3].
    After generation 1, points = [[0, 0, 0], [6, 6, 6], [3, 3, 3]]. The target = [3, 3, 3] is found in generation 1, so the smallest k is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n = points.size();

        if(n == 1) {
            if(points[0] == target)
                return 0;
            return -1;
        }

        int gen = 0;
        set<vector<int>> st;
        for(auto i : points)
            st.insert(i);

        if(st.find(target) != st.end())
            return 0;

        while (true) {
            int oldN = points.size();

            // Generate generation gen + 1
            for (int i = 0; i < oldN; i++) {
                for (int j = i + 1; j < oldN; j++) {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int z1 = points[i][2];

                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int z2 = points[j][2];

                    int x3 = (x1 + x2) / 2;
                    int y3 = (y1 + y2) / 2;
                    int z3 = (z1 + z2) / 2;

                    vector<int> p = {x3, y3, z3};

                    if (p == target)
                        return gen + 1;

                    if (st.find(p) == st.end()) {
                        st.insert(p);
                        points.push_back(p);
                    }
                }
            }

            // No new points => target can never be generated
            if (points.size() == oldN)
                return -1;

            gen++;
        }

        return -1;
    }
};