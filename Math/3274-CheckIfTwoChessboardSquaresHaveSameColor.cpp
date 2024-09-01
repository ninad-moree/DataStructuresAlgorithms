/*
    You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
    Below is the chessboard for reference. Return true if these two squares have the same color and false otherwise.
    The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the
    number second (indicating its row).


    Example 1:
    Input: coordinate1 = "a1", coordinate2 = "c3"
    Output: true
    Explanation: Both squares are black.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        coordinate1[0] = coordinate1[0] - 'a' + '1';
        coordinate2[0] = coordinate2[0] - 'a' + '1';
        
        int c10 = coordinate1[0] - '0';
        int c11 = coordinate1[1] - '0';

        int c20 = coordinate2[0] - '0';
        int c21 = coordinate2[1] - '0';

        int color1; // 0 white, 1 black
        int color2;

        if(c10%2 == 0 && c11%2 != 0 || c10%2 !=0 && c11%2 == 0)
            color1 = 0;
        else if(c10%2 == 0 && c11%2 == 0 || c10%2 !=0 && c11%2 != 0)
            color1 = 1;

        if(c20%2 == 0 && c21%2 != 0 || c20%2 !=0 && c21%2 == 0)
            color2 = 0;
        else if(c20%2 == 0 && c21%2 == 0 || c20%2 !=0 && c21%2 != 0)
            color2 = 1;

        return color1 == color2;
    }
};