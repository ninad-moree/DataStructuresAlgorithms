/*
    You are given an m x n integer matrix grid and an integer k. For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct 
    values within that submatrix. Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner 
    is (i, j) in grid. Note: If all elements in the submatrix have the same value, the answer will be 0. A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all 
    cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.

    Example 1:
    Input: grid = [[1,8],[3,-2]], k = 2
    Output: [[2]]
    Explanation: There is only one possible k x k submatrix: [[1, 8], [3, -2]]. Distinct values in the submatrix are [1, 8, 3, -2]. The minimum absolute difference in the submatrix 
    is |1 - 3| = 2. Thus, the answer is [[2]].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int i=0; i+k<=n; i++) {
            for(int j=0; j+k<=m; j++) {
                vector<int> arr;

                for(int x=i; x<i+k; x++) {
                    for(int y=j; y<j+k; y++) 
                        arr.push_back(grid[x][y]);
                }

                sort(arr.begin(), arr.end());
                int mini = INT_MAX;

                for(int k=1; k<arr.size(); k++) {
                    if(arr[k] == arr[k-1])
                        continue;
                    mini = min(mini, arr[k] - arr[k-1]);
                }

                if(mini != INT_MAX)
                    ans[i][j] = mini;
            }
        }

        return ans;
    }
};