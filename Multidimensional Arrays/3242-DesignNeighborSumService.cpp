/*
    You are given a n x n 2D array grid containing distinct elements in the range [0, n2 - 1]. Implement the neighborSum class:
    neighborSum(int [][]grid) initializes the object.
    int adjacentSum(int value) returns the sum of elements which are adjacent neighbors of value, that is either to the top, left, right, or bottom of 
    value in grid.
    int diagonalSum(int value) returns the sum of elements which are diagonal neighbors of value, that is either to the top-left, top-right, bottom-left,
    or bottom-right of value in grid.

    Example 1:
    Input: ["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"] ,[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]
    Output: [null, 6, 16, 16, 4]
*/

#include<bits/stdc++.h>
using namespace std;

class neighborSum {
public:
    vector<vector<int>> arr;
    int n;
    
    neighborSum(vector<vector<int>>& grid) {
        arr = grid;
        n = arr.size();
    }
    
    int adjacentSum(int value) {
        int ans = 0;
        int x=-1, y=-1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] == value) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        if(x == -1 || y == -1)
            return -1;
        
        if (x > 0) 
            ans += arr[x-1][y]; 
        if (x < n-1) 
            ans += arr[x+1][y];
        if (y > 0) 
            ans += arr[x][y-1];
        if (y < n-1) 
            ans += arr[x][y+1]; 
        
        return ans;
    }
    
    int diagonalSum(int value) {
        int ans = 0;
        int x=-1, y=-1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] == value) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        if (x > 0 && y > 0) 
            ans += arr[x-1][y-1]; 
        if (x > 0 && y < n-1) 
            ans += arr[x-1][y+1]; 
        if (x < n-1 && y > 0) 
            ans += arr[x+1][y-1];
        if (x < n-1 && y < n-1) 
            ans += arr[x+1][y+1]; 
        
        return ans;
    }
};
