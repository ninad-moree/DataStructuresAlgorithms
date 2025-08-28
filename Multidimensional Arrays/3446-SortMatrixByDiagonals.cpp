/*
    You are given an n x n square matrix of integers grid. Return the matrix such that: The diagonals in the bottom-left triangle (including the middle
    diagonal) are sorted in non-increasing order. The diagonals in the top-right triangle are sorted in non-decreasing order.

    Example 1:
    Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
    Output: [[8,2,3],[9,6,7],[4,5,1]]
    Explanation: The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
    [1, 8, 6] becomes [8, 6, 1].
    [9, 5] and [4] remain unchanged.
    The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
    [7, 2] becomes [2, 7].
    [3] remains unchanged.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<row; i++) {
            for(int j=0; j<row; j++) 
                mp[i - j].push_back(grid[i][j]);
        }

        for(auto &i : mp) {
            if(i.first >= 0) 
                sort(i.second.rbegin(), i.second.rend());
            else
                sort(i.second.begin(), i.second.end());
        }

        unordered_map<int, int> idx;
        for(int i=0; i<row; i++) {
            for(int j=0; j<row; j++) {
                int key = i - j;
                grid[i][j] = mp[key][idx[key]];
                idx[key]++;
            }   
        }

        return grid;
    }
};