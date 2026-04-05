/*
    There is a dungeon with n x m rooms arranged as a grid. You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you
    can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and
    two seconds for the next, alternating between the two. Return the minimum time to reach the room (n - 1, m - 1). Two rooms are adjacent if they share a common wall, either 
    horizontally or vertically.

    Example 1:
    Input: moveTime = [[0,4],[4,4]]
    Output: 7
    Explanation: The minimum time required is 7 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second. At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<vector<int>>> time(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {time, x, y, parity}

        time[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!pq.empty()) {
            auto curr = pq.top(); 
            int t = curr[0];
            int x = curr[1];
            int y = curr[2];
            int p = curr[3];
            pq.pop();

            if(t > time[x][y][p]) 
                continue;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int moveCost = (p == 0 ? 1 : 2);

                int startTime = max(t, moveTime[nx][ny]);
                int newTime = startTime + moveCost;

                int newParity = 1 - p;

                if(time[nx][ny][newParity] > newTime) {
                    time[nx][ny][newParity] = newTime;
                    pq.push({newTime, nx, ny, newParity});
                }
            }
        }

        int ans = min(time[n-1][m-1][0], time[n-1][m-1][1]);
        return ans == INT_MAX ? -1 : ans;
    }
};