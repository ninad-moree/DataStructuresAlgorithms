/*
    There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must 
    do the following routine for n minutes:
    At the first minute, color any arbitrary unit cell blue.
    Every minute thereafter, color blue every uncolored cell that touches a blue cell.
    Return the number of colored cells at the end of n minutes.

    Example 1:
    Input: n = 1
    Output: 1
    Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        ans = n*1LL*n + (n-1)*1LL*(n-1);
        return ans;
    }
};