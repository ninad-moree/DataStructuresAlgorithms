/*
    You are given two integer arrays start and target, where each array is of the form [x, y] representing a cell on a standard 8 x 8 chessboard.
    Return true if a knight can move from start to target in an even number of moves. Otherwise, return false.
    Note: A valid knight move consists of moving two squares in one direction and one square perpendicular to it. The figure below illustrates all eight possible moves from a cell.

    Example 1:
    Input: start = [1,1], target = [2,2]
    Output: true
    Explanation: One possible sequence of moves is (1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2). The knight reaches the target in 4 moves, which is even. Thus, the answer is
    true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        vector<vector<int>> moves = {
            {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
        };

        int ans = 0;
        
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        vector<vector<int>> vis(8, vector<int>(8));
        vis[start[0]][start[1]] = 1;

        while(!q.empty()) {
            int s = q.size();
            
            while(s--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == target[0] && y == target[1])
                    return ans % 2 == 0;

                for(int i=0; i<8; i++) {
                    int nx = x + moves[i][0];
                    int ny = y + moves[i][1];

                    if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[nx][ny]) {
                        
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            ans++;
        }

        return false;
    }
};