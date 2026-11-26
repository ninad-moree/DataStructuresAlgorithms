/*
    Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first. Alice starts by removing exactly 10 stones on her first turn.
    For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent. The player who cannot make a move loses the game. Given a positive integer n,
    return true if Alice wins the game and false otherwise.

    Example 1:
    Input: n = 12
    Output: true
    Explanation: Alice removes 10 stones on her first turn, leaving 2 stones for Bob. Bob cannot remove 9 stones, so Alice wins.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10)
            return false;

        bool isAlice = true;
        int curr = 10;

        while(n > 0) {
            if(n < curr) 
                return isAlice ? false : true;
            
            n -= curr;
            curr--;
            isAlice = !isAlice;
        }

        return isAlice ? false : true;
    }
};