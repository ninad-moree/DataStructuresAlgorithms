/*
    Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:
    Players take turns placing characters into empty squares ' '.
    The first player A always places 'X' characters, while the second player B always places 'O' characters.
    'X' and 'O' characters are always placed into empty squares, never on filled ones.
    The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.
    Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on 
    grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return 
    "Draw". If there are still movements to play return "Pending".
    You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, 
    and A will play first.

    Example 1:
    Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
    Output: "A"
    Explanation: A wins, they always play first.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));

    for (int i = 0; i < moves.size(); ++i) {
        int row = moves[i][0];
        int col = moves[i][1];

        char player = (i % 2 == 0) ? 'X' : 'O';
        grid[row][col] = player;

        if (i >= 4) {
            if ((grid[row][0] == player && grid[row][1] == player && grid[row][2] == player) ||
                (grid[0][col] == player && grid[1][col] == player && grid[2][col] == player) ||
                (row == col && grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
                (row + col == 2 && grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
                ) {
                return (player == 'X') ? "A" : "B"; 
            }
        }
    }

    return (moves.size() == 9) ? "Draw" : "Pending";
    }
};