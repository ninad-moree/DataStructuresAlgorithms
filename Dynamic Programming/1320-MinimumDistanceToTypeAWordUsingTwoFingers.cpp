/*
    You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate. For example, the letter 'A' is located at 
    coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1). Given 
    the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + 
    |y1 - y2|. Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at
    the first letter or the first two letters.

    Example 1:
    Input: word = "CAKE"
    Output: 3
    Explanation: Using two fingers, one optimal way to type "CAKE" is: 
    Finger 1 on letter 'C' -> cost = 0  Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
    Finger 2 on letter 'K' -> cost = 0  Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
    Total distance = 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        if(a == -1)
            return 0;
        int x1 = a/6;
        int y1 = a%6;

        int x2 = b/6;
        int y2 = b%6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int idx, int f1, int f2, string& word, vector<vector<vector<int>>>& dp) {
        if(idx == word.size())
            return 0;

        if(dp[idx][f1 + 1][f2 + 1] != -1)
            return dp[idx][f1 + 1][f2 + 1];

        int cur = word[idx] - 'A';

        int useF1 = dist(f1, cur) + solve(idx+1, cur, f2, word, dp);
        int useF2 = dist(f2, cur) + solve(idx+1, f1, cur, word, dp);

        return dp[idx][f1 + 1][f2 + 1] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        int n = word.size() + 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return solve(0, -1, -1, word, dp);
    }
};