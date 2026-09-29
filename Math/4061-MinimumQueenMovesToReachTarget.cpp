/*
    There is an 8 x 8 empty chessboard with 1-indexed rows and columns. You are given an array source = [sr, sc] representing the starting position of a queen, and an array 
    target = [tr, tc] representing the target position. In one move, the queen travels one or more squares along a single row, column, or diagonal, staying within the board.
    Return the minimum number of moves for the queen to land exactly on target.

    Example 1:
    Input: source = [8,1], target = [1,8]
    Output: 1
    Explanation: A single diagonal move takes the queen straight from (8, 1) to (1, 8).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]) 
            return 0;

        // same row 
        if(source[0] == target[0]) 
            return 1;

        // same col
        if(source[1] == target[1]) 
            return 1;

        // diagonal
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) 
            return 1;

        return 2;
    }
};