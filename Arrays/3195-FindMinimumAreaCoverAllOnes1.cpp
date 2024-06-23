/*
    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid
    lie inside this rectangle. Return the minimum possible area of the rectangle.

    Example 1:
    Input: grid = [[0,1,0],[1,0,1]]
    Output: 6
    Explanation:
    The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int>x;
        vector<int>y;
        
        for(int i = 0 ; i< grid.size();i++){
            for(int j= 0 ; j < grid[0].size() ;j++){
               if(grid[i][j]==1){
                   x.push_back(j);
                   y.push_back(i);
               }
            }
        }
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        return (x[x.size()-1]-x[0]+1)*(y[y.size()-1]-y[0]+1);
    }
};