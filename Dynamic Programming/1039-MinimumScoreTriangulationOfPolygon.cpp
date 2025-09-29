/*
    You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
    Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no
    other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles. You will triangulate the polygon. For each triangle, the weight of that
    triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles. Return the minimum possible score
    that you can achieve with some triangulation of the polygon.

    Example 1:
    Input: values = [1,2,3]
    Output: 6
    Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
        }
        
        return dp[0][n-1];
    }
};