/*
    You are given a 0-indexed m x n binary matrix grid.
    A 0-indexed m x n difference matrix diff is created with the following procedure:
        Let the number of ones in the ith row be onesRowi.
        Let the number of ones in the jth column be onesColj.
        Let the number of zeros in the ith row be zerosRowi.
        Let the number of zeros in the jth column be zerosColj.
        diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
    Return the difference matrix diff.

    Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
    Output: [[0,0,4],[0,0,4],[-2,-2,2]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> zeroRows(grid.size(), 0);
        vector<int> zeroCols(grid[0].size(), 0);
        vector<int> oneRows(grid.size(), 0);
        vector<int> oneCols(grid[0].size(), 0);

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    zeroRows[i]++;
                    zeroCols[j]++;
                } else {
                    oneRows[i]++;
                    oneCols[j]++;
                }
            }
        }

        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) 
                ans[i][j] = oneRows[i] + oneCols[j] - zeroRows[i] - zeroCols[j];
        }

        return ans;
    }
};