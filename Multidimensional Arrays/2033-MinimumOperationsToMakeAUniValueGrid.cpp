/*
    You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid. A uni-value grid is a grid 
    where all the elements of it are equal. Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

    Example 1:
    Input: grid = [[2,4],[6,8]], x = 2
    Output: 4
    Explanation: We can make every element equal to 4 by doing the following:  - Add x to 2 once. - Subtract x from 6 once. - Subtract x from 8 twice. 
    A total of 4 operations were used.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int rem = grid[0][0] % x;

        vector<int> nums;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] % x != rem)
                    return -1;
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ans = 0;
        for (int num : nums) 
            ans += abs(num - median) / x;

        return ans;
    }
};