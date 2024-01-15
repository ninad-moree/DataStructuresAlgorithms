/*
    There is a 1-indexed 8 x 8 chessboard containing 3 pieces.
    You are given 6 integers a, b, c, d, e, and f where:
    (a, b) denotes the position of the white rook.
    (c, d) denotes the position of the white bishop.
    (e, f) denotes the position of the black queen.
    Given that you can only move the white pieces, 
    return the minimum number of moves required to capture the black queen.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a == e && !(a == c && d > min(b,f) && d < max(b,f) )) 
            return 1; 

        if(b == f && !(b == d && c > min(a,e) && c < max(a,e) ))  
            return 1;  

        if(c + d == e + f && !(c + d == a + b && a > min(c , e) && a < max(c, e) )) 
            return 1;  
            
        if(c-d == e-f && !( c-d == a-b && a > min(c , e) && a < max(c, e) )) 
            return 1;  
            
        return 2;
    }
};