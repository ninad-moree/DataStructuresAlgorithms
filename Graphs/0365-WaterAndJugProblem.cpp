/*
    You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using
    the following operations: Fill either jug completely with water. Completely empty either jug. Pour water from one jug into another until the receiving jug is full, or the 
    transferring jug is empty.

    Example 1:
    Input: x = 3, y = 5, target = 4
    Output: true
    Explanation: Follow these steps to reach a total of 4 liters: Fill the 5-liter jug (0, 5). Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
    Empty the 3-liter jug (0, 2). Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0). Fill the 5-liter jug again (2, 5). Pour from the 5-liter jug into the 
    3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4). Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).
*/

#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(x + 1, vector<int>(y + 1));

        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()) {
            int s = q.size();

            while(s--) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();

                if(a + b == target)
                    return true;

                // fill x completely
                if(!vis[x][b]) {
                    q.push({x, b});
                    vis[x][b] = 1;
                }

                // fill y completely
                if(!vis[a][y]) {
                    q.push({a, y});
                    vis[a][y] = 1;
                }

                // empty x
                if(!vis[0][b]) {
                    q.push({0, b});
                    vis[0][b] = 1;
                }
                // empty y
                if(!vis[a][0]) {
                    q.push({a, 0});
                    vis[a][0] = 1;
                }
                // pour to x from y
                int remX = x - a;
                if(b >= remX) {
                    int newX = x;
                    int newY = b - remX;
                    
                    if(!vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = 1;
                    }
                } else {
                    int newX = a + b;
                    int newY = 0;

                    if(!vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = 1;
                    }
                }

                // pour to y from x
                int remY = y - b;
                if(a >= remY) {
                    int newX = a - remY;
                    int newY = y;
                    
                    if(!vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = 1;
                    }
                } else {
                    int newX = 0;
                    int newY = a + b;

                    if(!vis[newX][newY]) {
                        q.push({newX, newY});
                        vis[newX][newY] = 1;
                    }
                }
            }
        }

        return false;
    }
};