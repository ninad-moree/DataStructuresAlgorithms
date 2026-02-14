/*
    We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne. Then, some 
    champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right 
    of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess 
    champagne fall on the floor.) For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the 
    second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, 
    the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below. Now after pouring some non-negative integer cups of champagne, 
    return how full the jth glass in the ith row is (both i and j are 0-indexed.)

    Example 1:
    Input: poured = 1, query_row = 1, query_glass = 1
    Output: 0.00000
    Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will 
    remain empty.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double solve(int poured, int row, int col, vector<vector<double>>& dp) {
        if(row < 0 || col < 0 || row < col)
            return 0.0;
        if(row == 0 && col == 0)
            return poured;

        if(dp[row][col] != -1)
            return dp[row][col];

        double left = (solve(poured, row-1, col, dp) - 1) / 2.0;
        double right = (solve(poured, row-1, col-1, dp) - 1) / 2.0;

        if(left < 0)
            left = 0.0;
        if(right < 0)
            right = 0.0;

        return dp[row][col] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, -1));

        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};