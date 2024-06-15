/*
    You are given two positive integers n and k. There are n children numbered from 0 to n - 1 standing in a queue in order from left to right.
    Initially, child 0 holds a ball and the direction of passing the ball is towards the right direction. After each second, the child holding 
    the ball passes it to the child next to them. Once the ball reaches either end of the line, i.e. child 0 or child n - 1, the direction of 
    passing is reversed. Return the number of the child who receives the ball after k seconds.

    Example 1:
    Input: n = 3, k = 5
    Output: 1
    Explanation:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int idx = 0;
        int dir = 1;

        for(int i=0; i<k; i++) {
            idx += dir;

            if(idx == n-1)
                dir = -1;
            if(idx == 0)
                dir = 1;
        }

        return idx;
    }
};  