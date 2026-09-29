/*
    You are given a 0-indexed 2D integer array grid of size m x n that represents a map of the items in a shop. The integers in the grid represent the following: 0 represents a
    wall that you cannot pass through. 1 represents an empty cell that you can freely move to and from. All other positive integers represent the price of an item in that cell. 
    You may also freely move to and from these item cells. It takes 1 step to travel between adjacent grid cells. You are also given integer arrays pricing and start where 
    pricing = [low, high] and start = [row, col] indicates that you start at the position (row, col) and are interested only in items with a price in the range of [low, high] 
    (inclusive). You are further given an integer k. You are interested in the positions of the k highest-ranked items whose prices are within the given price range. The rank is
    determined by the first of these criteria that is different: Distance, defined as the length of the shortest path from the start (shorter distance has a higher rank).
    Price (lower price has a higher rank, but it must be in the price range). The row number (smaller row number has a higher rank). The column number (smaller column number has
    a higher rank). Return the k highest-ranked items within the price range sorted by their rank (highest to lowest). If there are fewer than k reachable items within the price
    range, return all of them.

    Example 1:
    Input: grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], start = [0,0], k = 3
    Output: [[0,1],[1,1],[2,1]]
    Explanation: You start at (0,0). With a price range of [2,5], we can take items from (0,1), (1,1), (2,1) and (2,2).
    The ranks of these items are: - (0,1) with distance 1 - (1,1) with distance 2 - (2,1) with distance 3 - (2,2) with distance 4
    Thus, the 3 highest ranked items in the price range are (0,1), (1,1), and (2,1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int sx = start[0];
        int sy = start[1];
        
        int low = pricing[0];
        int high = pricing[1];

        if(grid[sx][sy] == 0)
            return {};

        queue<pair<int, int>> q; // {x, y}
        vector<vector<int>> dist(n, vector<int>(m, -1));

        q.push({sx, sy});
        dist[sx][sy] = 0;

        vector<vector<int>> item;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (grid[x][y] >= low && grid[x][y] <= high) 
                item.push_back({dist[x][y], grid[x][y], x, y});

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 0 && dist[nx][ny] == -1) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }

        sort(item.begin(), item.end(),
            [](vector<int>& a, vector<int>& b) {
                if(a[0] != b[0])
                    return a[0] < b[0];

                if(a[1] != b[1])
                    return a[1] < b[1];

                if(a[2] != b[2])
                    return a[2] < b[2];

                return a[3] < b[3];
            }
        );

        vector<vector<int>> ans;

        for (int i = 0; i < min(k, (int)item.size()); i++) 
            ans.push_back({item[i][2], item[i][3]});

        return ans;
    }
};