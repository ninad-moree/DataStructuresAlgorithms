/*
    You are given an integer n representing the number of players in a game and a 2D array pick where pick[i] = [xi, yi] represents that the player xi 
    picked a ball of color yi.
    Player i wins the game if they pick strictly more than i balls of the same color. In other words,
    Player 0 wins if they pick any ball.
    Player 1 wins if they pick at least two balls of the same color.
    Player i wins if they pick at leasti + 1 balls of the same color.
    Return the number of players who win the game.
    Note that multiple players can win the game.

    Example 1:
    Input: n = 4, pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]
    Output: 2
    Explanation:
    Player 0 and player 1 win the game, while players 2 and 3 do not win.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int, map<int,int>>mp;

        for(auto i:pick)
           mp[i[0]][i[1]]++;
        
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(auto j : mp[i]) {
                if(j.second > i) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};