/*
    There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the 
    matrix, respectively. Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where 
    cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1). You want 
    to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in 
    the bottom row. You can only travel in the four cardinal directions (left, right, up, and down). Return the last day where it is possible to walk from the top to the bottom 
    by only walking on land cells.

    Example 1:
    Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
    Output: 2
    Explanation: The above image depicts how the matrix changes each day starting from day 0. The last day where it is possible to cross from top to bottom is on day 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<int>> mat(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        for(int i=0; i<day; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            mat[x][y] = 1;
        }

        for(int i=0; i<col; i++) {
            if(mat[0][i] == 0) {
                q.push({0, i});
                vis[0][i] = true;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == row - 1)
                return true;

            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < row && newY >= 0 && newY < col && mat[newX][newY] == 0 && !vis[newX][newY]) {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1;
        int high = cells.size();
        int time = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(canCross(row, col, mid, cells)) {
                time = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        return time;
    }
};