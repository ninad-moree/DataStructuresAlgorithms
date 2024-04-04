/*
    You are given a binary array possible of length n. Danielchandg and Bob are playing a game that consists of n levels. Some of the levels in the 
    game are impossible to clear while others can always be cleared. In particular, if possible[i] == 0, then the ith level is impossible to clear 
    for both the players. A player gains 1 point on clearing a level and loses 1 point if the player fails to clear it. At the start of the game, 
    Danielchandg will play some levels in the given order starting from the 0th level, after which  Bob will play for the rest of the levels.
    Danielchandg wants to know the minimum number of levels he should play to gain more points than Bob, if both players play optimally to maximize 
    their points. Return the minimum number of levels danielchandg should play to gain more points. If this is not possible, return -1.

    Example 1:
    Input: possible = [1,0,1,0]
    Output: 1
    Explanation:
    Let's look at all the levels that Danielchandg can play up to:
    If Danielchandg plays only level 0 and Bob plays the rest of the levels, Danielchandg has 1 point, while Bob has -1 + 1 - 1 = -1 point.
    If Danielchandg plays till level 1 and Bob plays the rest of the levels, Danielchandg has 1 - 1 = 0 points, while Bob has 1 - 1 = 0 points.
    If Danielchandg plays till level 2 and Bob plays the rest of the levels, Danielchandg has 1 - 1 + 1 = 1 point, while Bob has -1 point.
    Danielchandg must play a minimum of 1 level to gain more points.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int bob = 0;
        int dan = 0;

        for(auto i : possible) {
            if(i==1)
                bob += 1;
            else
                bob -= 1;
        }

        for(int i=0; i<possible.size()-1; i++) {
            if(possible[i] == 1) {
                dan += 1;
                bob -= 1;
            } else {
                dan -= 1;
                bob += 1;
            }

            if(dan > bob)
                return i+1;
        }

        return -1;
    }
};