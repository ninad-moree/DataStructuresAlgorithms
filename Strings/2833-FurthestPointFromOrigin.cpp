/*
    You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement 
    on a number line starting from the origin 0.
    In the ith move, you can choose one of the following directions:
    move to the left if moves[i] = 'L' or moves[i] = '_'
    move to the right if moves[i] = 'R' or moves[i] = '_'
    Return the distance from the origin of the furthest point you can get to after n moves.

    Example 1:
    Input: moves = "L_RL__R"
    Output: 3
    Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt_ = 0;
        int cntl = 0;
        int cntr = 0;

        for(auto i : moves) {
            if(i=='_')
                cnt_++;
            if(i=='L')
                cntl++;
            if(i=='R')
                cntr++;
        }

        if(cntl > cntr) 
            cntl += cnt_;
        else
            cntr += cnt_;
        
        return abs(cntl-cntr);
    }
};