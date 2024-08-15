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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int c = image[sr][sc];
        image[sr][sc] = color;

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            int s = q.size();

            for(int i=0; i<s; i++) {
                auto f = q.front();
                q.pop();
                int x = f.first;
                int y = f.second;

                for(auto d : dir) {
                    int newX = x + d.first;
                    int newY = y + d.second;

                    if(newX>=0 && newX<n && newY>=0 && newY<m && image[newX][newY] == c && !vis[newX][newY]) {
                        vis[newX][newY] = 1;
                        image[newX][newY] = color;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return image;
    }
};