/*
    A certain bug's home is on the x-axis at position x. Help them get there from position 0. The bug jumps according to the following rules: It can jump exactly a positions 
    forward (to the right). It can jump exactly b positions backward (to the left). It cannot jump backward twice in a row. It cannot jump to any forbidden positions.
    The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers. Given an array of integers forbidden, where forbidden[i] means 
    that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no 
    possible sequence of jumps that lands the bug on position x, return -1.

    Example 1:
    Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
    Output: 3
    Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/* ======================================================================= USING DYNAMIC PROGRAMMING ======================================================================== */ 
    int solve(int idx, int prev, unordered_map<int, int>& forb, int a, int b, int x, vector<vector<int>>& dp, vector<vector<int>>& vis) {
        if(idx < 0 || forb.count(idx) || idx > 6000)
            return 1e9;

        if(idx == x)
            return 0;

        if(dp[idx][prev] != -1)
            return dp[idx][prev];

        // cycle detected
        if(vis[idx][prev])
            return 1e9;

        vis[idx][prev] = 1;

        int left = 1e9;

        if(prev == 0 && idx - b >= 0)
            left = 1 + solve(idx - b, 1, forb, a, b, x, dp, vis);
        
        int right = 1 + solve(idx + a, 0, forb, a, b, x, dp, vis);

        vis[idx][prev] = 0;

        return dp[idx][prev] = min(left, right);
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> forb;
        for(auto i : forbidden)
            forb[i]++;

        vector<vector<int>> dp(6001, vector<int>(2, -1));
        vector<vector<int>> vis(6001, vector<int>(2, 0));

        // prev--> 0 - not back, 1 - back
        int ans = solve(0, 0, forb, a, b, x, dp, vis);
        return ans == 1e9 ? -1 : ans;
    }

/* ============================================================================ USING BFS (GRAPH) ============================================================================ */
    int minimumJumps2(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> forb;
        for(auto i : forbidden)
            forb[i]++;

        // [pos][prev]: prev = 0 -> prev jump forward, prev = 1 -> prev jump backward
        vector<vector<bool>> vis(6001, vector<bool>(2, false));
        queue<pair<int, int>> q; // {pos, backward}
        
        q.push({0, 0});
        vis[0][0] = 1;
        int steps = 0;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int pos = q.front().first;
                int prev = q.front().second;
                q.pop();

                if(pos == x)
                    return steps;

                // jump forward
                int nextPos = pos + a;
                if(nextPos <= 6000 && !forb.count(nextPos) && !vis[nextPos][0]) {
                    q.push({nextPos, 0});
                    vis[nextPos][0] = 1;
                }

                // jump backward
                nextPos = pos - b;
                if(prev == 0 && nextPos >= 0 && !forb.count(nextPos) && !vis[nextPos][1]) {
                    q.push({nextPos, 1});
                    vis[nextPos][1] = 1;
                }
            }

            steps++;
        }

        return -1;
    }
};