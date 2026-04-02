/*
    You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location
    of the bomb. The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the 
    location of the ith bomb, whereas ri denotes the radius of its range. You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie
    in its range. These bombs will further detonate the bombs that lie in their ranges. Given the list of bombs, return the maximum number of bombs that can be detonated if you 
    are allowed to detonate only one bomb.

    Example 1:
    Input: bombs = [[2,1,3],[6,1,4]]
    Output: 2
    Explanation: The above figure shows the positions and ranges of the 2 bombs. If we detonate the left bomb, the right bomb will not be affected. But if we detonate the right
    bomb, both  bombs will be detonated. So the maximum bombs that can be detonated is max(1, 2) = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int& node, vector<vector<int>>& adj, vector<int>& vis, int& cnt) {
        vis[node] = 1;
        cnt++;

        for(auto i : adj[node]) {
            if(!vis[i])
                dfs(i, adj, vis, cnt);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for(int j=0; j<n; j++) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                if(i != j) {
                    long long x = abs(x1 - x2);
                    long long y = abs(y1 - y2);

                    if(x*x + y*y <= r1*r1)
                        adj[i].push_back(j);
                    }
            }
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            vector<int> vis(n);

            dfs(i, adj, vis, cnt);
            ans = max(ans, cnt);
        }

        return ans;
    }
};