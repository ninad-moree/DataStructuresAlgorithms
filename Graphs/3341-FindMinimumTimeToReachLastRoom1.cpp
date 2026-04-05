/*
    There is a dungeon with n x m rooms arranged as a grid. You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds after 
    which the room opens and can be moved to. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one 
    second. Return the minimum time to reach the room (n - 1, m - 1). Two rooms are adjacent if they share a common wall, either horizontally or vertically.

    Example 1:
    Input: moveTime = [[0,4],[4,4]]
    Output: 6
    Explanation: The minimum time required is 6 seconds.
    At time t == 4, move from room (0, 0) to room (1, 0) in one second. At time t == 5, move from room (1, 0) to room (1, 1) in one second.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int ans = 0;

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        time[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //{time, {x, y}}
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int t = pq.top().first;
            pq.pop();

            if(vis[x][y])
                continue;
            vis[x][y] = 1;

            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX < 0 || newX >= n || newY < 0 || newY >= m)
                    continue;

                int newTime = 1 + max(time[x][y], moveTime[newX][newY]);

                if(time[newX][newY] > newTime) {
                    time[newX][newY] = newTime;
                    pq.push({newTime, {newX, newY}});
                }
                
            }
        }

        return time[n-1][m-1];
    }
};