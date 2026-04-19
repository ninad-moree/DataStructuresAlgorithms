/*
    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image. You are also given three 
    integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc]. To perform a flood fill, consider 
    the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels 
    connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
    Return the modified image after performing the flood fill.

    Example 1:
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color 
    as the starting pixel (i.e., the blue pixels) are colored with the new color.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int dx[], int dy[], int newColor, int prevColor) {
        ans[row][col] = newColor;
        int m = image.size();
        int n = image[0].size();

        for(int i=0; i<4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && image[nrow][ncol] == prevColor && ans[nrow][ncol] != newColor)
                dfs(nrow, ncol, image, ans, dx, dy, newColor, prevColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;

        int m = image.size();
        int n = image[0].size();
        int prevColor = image[sr][sc];
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        dfs(sr, sc, image, ans, dx, dy, color, prevColor);

        return ans;
    }

    // BFS
    vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> ans = image;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        q.push({sr, sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        int st = image[sr][sc];

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && image[newX][newY] == st) {
                    ans[newX][newY] = color;
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }

        return ans;
    }
};