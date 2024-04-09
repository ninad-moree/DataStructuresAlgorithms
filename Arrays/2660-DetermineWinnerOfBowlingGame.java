/*
    You are given two 0-indexed integer arrays player1 and player2, that represent the number of pins that player 1 and player 2 hit in a 
    bowling game, respectively. The bowling game consists of n turns, and the number of pins in each turn is exactly 10. Assume a player hit 
    xi pins in the ith turn. The value of the ith turn for the player is:
        2xi if the player hit 10 pins in any of the previous two turns.
        Otherwise, It is xi.
    The score of the player is the sum of the values of their n turns.
    Return
    1 if the score of player 1 is more than the score of player 2,
    2 if the score of player 2 is more than the score of player 1, and
    0 in case of a draw.

    Example 1:
    Input: player1 = [4,10,7,9], player2 = [6,5,2,3]
    Output: 1
    Explanation: The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
    The score of player2 is 6 + 5 + 2 + 3 = 16.
    Score of player1 is more than the score of player2, so, player1 is the winner, and the answer is 1.
*/

class Solution {
    public int isWinner(int[] player1, int[] player2) {
        if(player1.length == 1) {
            if(player1[0] == player2[0])
                return 0;
            else if(player1[0] > player2[0])
                return 1;
            else
                return 2;
        }

        int p1 = player1[0];
        int p2 = player2[0];

        if(player1[0] == 10) 
            p1 += 2*player1[1];
        else
            p1 += player1[1];

        if(player2[0] == 10)
                p2 += 2*player2[1];
        else
            p2 += player2[1];

       for(int i=2; i<player1.length; i++) {
            if(player1[i-1] == 10 || player1[i-2] == 10)
                p1 += 2*player1[i];
            else
                p1 += player1[i];
        }

        for(int i=2; i<player1.length; i++) {
            if(player2[i-1] == 10 || player2[i-2] == 10)
                p2 += 2*player2[i];
            else
                p2 += player2[i];
        }

        if(p1>p2)   return 1;
        else if(p2>p1) return 2;
        else return 0;
    }
}