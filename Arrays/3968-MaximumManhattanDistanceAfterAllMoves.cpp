/*
    You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'. Starting from the origin (0, 0), each character represents one move on a 2D plane:
    'U': Move up by 1 unit. 'D': Move down by 1 unit. 'L': Move left by 1 unit. 'R': Move right by 1 unit. '_': Can be replaced with any one of 'U', 'D', 'L', or 'R'.
    Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

    Example 1:
    Input: moves = "L_D_"
    Output: 4
    Explanation: One optimal choice is: 'L': (0, 0) -> (-1, 0); '_' treated as 'D': (-1, 0) -> (-1, -1); 'D': (-1, -1) -> (-1, -2); '_' treated as 'L': (-1, -2) -> (-2, -2)
    The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int dash = 0;
        for(auto i : moves) {
            if(i == '_')
                dash++;
        }

        int ans = dash;
        int x = 0;
        int y = 0;

        for(auto i : moves) {
            if(i == 'U')
                x++;
            else if(i == 'D')
                x--;
            else if(i == 'L')
                y--;
            else if(i == 'R')
                y++;
        }

        ans += (abs(x) + abs(y));
        return ans;
    }
};