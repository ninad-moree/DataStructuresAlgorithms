/*
    You are at the side of a river. You are given a m litre jug and a n litre jug . Both the jugs are initially empty. The jugs dont have markings to allow measuring smaller 
    quantities. You have to use the jugs to measure d litres of water . Determine the minimum no of operations to be performed to obtain d litres of water in one of the jugs.
    The operations you can perform are: Empty a Jug, Fill a Jug Pour water from one jug to the other until one of the jugs is either empty or full.
    
    Examples:
    Input: m = 3, n = 5, d = 4
    Output: 6
    Explanation: Operations are as follow-
    1. Fill up the 5 litre jug.
    2. Then fill up the 3 litre jug using 5 litre jug. Now 5 litre jug contains 2 litre water.
    3. Empty the 3 litre jug.
    4. Now pour the 2 litre of water from 5 litre jug to 3 litre jug.
    5. Now 3 litre jug contains 2 litre of water and 5 litre jug is empty.
    6. Now fill up the 5 litre jug.
    7. Now fill one litre of water from 5 litre jug to 3 litre jug. Now we have 4 litre water in 5 litre jug.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int m, int n, int d) {
        if(d > max(m, n))
            return -1;
            
        queue<vector<int>> q; // {jug1, jug2, steps}
        vector<vector<bool>> vis(m+1, vector<bool>(n+1, false));
        
        q.push({0, 0, 0});
        vis[0][0] = 1;
        
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            
            int j1 = f[0];
            int j2 = f[1];
            int steps = f[2];
            
            if(j1 == d || j2 == d)
                return steps;
                
            // Fill Jug1
            if(!vis[m][j2]) {
                vis[m][j2] = 1;
                q.push({m, j2, steps+1});
            }
            
            // Fill Jug2
            if(!vis[j1][n]) {
                vis[j1][n] = 1;
                q.push({j1, n, steps+1});
            }
            
            // Empty Jug1
            if(!vis[0][j2]) {
                vis[0][j2] = 1;
                q.push({0, j2, steps+1});
            }
            
            // Empty Jug2
            if(!vis[j1][0]) {
                vis[j1][0] = 1;
                q.push({j1, 0, steps+1});
            }
            
            // Pour Jug1 to Jug2;
            int pour12 = min(j1, n - j2);
            if(!vis[j1 - pour12][j2 + pour12]) {
                vis[j1 - pour12][j2 + pour12] = 1;
                q.push({j1 - pour12, j2 + pour12, steps+1});
            }
            
            // Pour Jug2 to Jug1;
            int pour21 = min(m - j1, j2);
            if(!vis[j1 + pour21][j2 - pour21]) {
                vis[j1 + pour21][j2 - pour21] = 1;
                q.push({j1 + pour21, j2 - pour21, steps+1});
            }
        }
        
        return -1;
    }
};