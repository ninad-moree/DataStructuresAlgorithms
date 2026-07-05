/*
    You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'. You need to reach the top left 
    square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, 
    left or up-left (diagonally) only if there is no obstacle there. Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, 
    and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7. In case there is no path, return [0, 0].

    Example 1:
    Input: board = ["E23","2X2","12S"]
    Output: [7,1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    pair<int, long long> solve(int x, int y, vector<string>& board, vector<vector<pair<int, long long>>>& dp) {
        if(x == 0 && y == 0)
            return {0, 1};

        if(x < 0 || y < 0 || board[x][y] == 'X')
            return {INT_MIN, 0};

        if(dp[x][y].first != -1)
            return dp[x][y];

        pair<int, long long> up = solve(x-1, y, board, dp);
        pair<int, long long> left = solve(x, y-1, board, dp);
        pair<int, long long> upLeft = solve(x-1, y-1, board, dp);

        int maxi = max(up.first, max(left.first, upLeft.first));

        if(maxi == INT_MIN)
            return dp[x][y] = {INT_MIN, 0};
        
        long long ways = 0;
        if (up.first == maxi)     
            ways = (ways + up.second) % MOD;
        if (left.first == maxi)   
            ways = (ways + left.second) % MOD;
        if (upLeft.first == maxi) 
            ways = (ways + upLeft.second) % MOD;

        return dp[x][y] = {maxi + board[x][y] - '0', ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        if(board[n-1][m-1] == 'X' || board[0][0] == 'X')
            return {};

        board[n-1][m-1] = '0';
        board[0][0] = '0';

        vector<vector<pair<int, long long>>> dp(n+1, vector<pair<int, long long>>(m+1, {-1, -1}));

        pair<int, long long> res = solve(n-1, m-1, board, dp);

        if(res.first == INT_MIN)
            return {0, 0};

        return {res.first, (int)res.second};
    }
};