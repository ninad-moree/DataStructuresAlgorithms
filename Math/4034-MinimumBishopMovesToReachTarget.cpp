/*
    There is an 8 x 8 empty chessboard with 1-indexed rows and columns. You are given an array source = [sr, sc] representing the starting position of a bishop, and an array 
    target = [tr, tc] representing the target position. In one move, the bishop travels one or more squares along a single diagonal direction, staying within the board.
    Return the minimum number of moves for the bishop to land exactly on target. If it can never reach target, return -1.

    Example 1:
    Input: source = [8,1], target = [1,8]
    Output: 1
    Explanation: A single diagonal move takes the bishop straight from (8, 1) to (1, 8).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

        if (sr == tr && sc == tc) 
            return 0;

        if ((sr + sc) % 2 != (tr + tc) % 2) 
            return -1; // different color squares

        if (sr - sc == tr - tc || sr + sc == tr + tc) 
            return 1; // same diagonal

        return 2;


        /* SECOND APPROACH */
        // int dx[] = {-1, -1, 1, 1};
        // int dy[] = {-1, 1, -1, 1};

        // int sr = source[0] - 1;
        // int sc = source[1] - 1;
        // int tr = target[0] - 1;
        // int tc = target[1] - 1;

        // // Bishop can only move on squares of the same color
        // if ((sr + sc) % 2 != (tr + tc) % 2)
        //     return -1;

        // vector<vector<bool>> vis(8, vector<bool>(8, false));
        // queue<pair<int, int>> q;

        // q.push({sr, sc});
        // vis[sr][sc] = true;

        // int moves = 0;

        // while (!q.empty()) {
        //     int sz = q.size();

        //     while (sz--) {
        //         auto [x, y] = q.front();
        //         q.pop();

        //         if (x == tr && y == tc)
        //             return moves;

        //         // Try all 4 diagonal directions
        //         for (int d = 0; d < 4; d++) {
        //             int nx = x + dx[d];
        //             int ny = y + dy[d];

        //             // Bishop can travel multiple squares
        //             while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {

        //                 if (!vis[nx][ny]) {
        //                     vis[nx][ny] = true;
        //                     q.push({nx, ny});
        //                 }

        //                 nx += dx[d];
        //                 ny += dy[d];
        //             }
        //         }
        //     }

        //     moves++;
        // }

        // return -1;
    }
};