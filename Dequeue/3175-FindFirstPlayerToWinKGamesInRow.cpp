/*
    A competition consists of n players numbered from 0 to n - 1. You are given an integer array skills of size n and a positive integer k, where 
    skills[i] is the skill level of player i. All integers in skills are unique. All players are standing in a queue in order from player 0 to 
    player n - 1. The competition process is as follows:
    The first two players in the queue play a game, and the player with the higher skill level wins.
    After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.
    The winner of the competition is the first player who wins k games in a row.
    Return the initial index of the winning player.

    Example 1:
    Input: skills = [4,2,6,3,9], k = 2
    Output: 2
    Explanation:
    Initially, the queue of players is [0,1,2,3,4]. The following process happens:
    Players 0 and 1 play a game, since the skill of player 0 is higher than that of player 1, player 0 wins. The resulting queue is [0,2,3,4,1].
    Players 0 and 2 play a game, since the skill of player 2 is higher than that of player 0, player 2 wins. The resulting queue is [2,3,4,1,0].
    Players 2 and 3 play a game, since the skill of player 2 is higher than that of player 3, player 2 wins. The resulting queue is [2,4,1,0,3].
    Player 2 won k = 2 games in a row, so the winner is player 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        vector<int> temp = skills;

        int maxi = 0;
        int maxIdx = 0;
        for(int i=0; i<skills.size(); i++) {
            if(skills[i] > maxi) {
                maxi = skills[i];
                maxIdx = i;
            }
        }
        
        if(k >= skills.size())
            return maxIdx;

        deque<int> dq;
        for(int i=1; i<skills.size(); i++)
            dq.push_back(i);
        
        int winner = 0;
        int wins = 0;

        while(true) {
            int j = dq.front();
            dq.pop_front();

            if(skills[j] < skills[winner]) {
                wins++;
                dq.push_back(j);
            } else {
                wins = 1;
                dq.push_back(winner);
                winner = j;
            }

            if(wins == k)
                return winner;
        }

        return -1;
    }
};