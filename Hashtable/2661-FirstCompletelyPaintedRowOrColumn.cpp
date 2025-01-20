/*
    You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
    Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i]. Return the smallest index i at which 
    either a row or a column will be completely painted in mat.

    Example 1:
    Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
    Output: 2
    Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        unordered_map<int, pair<int,int>> mp;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) 
                mp[mat[i][j]] = {i,j};
        }

        map<int, int> row, col;

        for(int i=0; i<arr.size(); i++) {
            auto ele = mp[arr[i]];
            row[ele.first] += 1;
            col[ele.second] += 1;

            if(row[ele.first] == mat[0].size() || col[ele.second] == mat.size())
                return i;
        }

        return -1;
    }
};