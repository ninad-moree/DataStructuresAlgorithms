/*
    Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
    Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
    Return the minimum time Bob needs to make the rope colorful.

    Example 1:
    Input: colors = "abaac", neededTime = [1,2,3,4,5]
    Output: 3
    Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
    Bob can remove the blue balloon at index 2. This takes 3 seconds.
    There are no longer two consecutive balloons of the same color. Total time = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinCost(int i, string& colorSeq, vector<int>& reqTime, vector<int>& memo, char prevColor, int prevTime) {
        if (i < 0) 
            return 0;
        
        if (memo[i] != -1) 
            return memo[i];
        
        if (colorSeq[i] == prevColor) 
            return memo[i] = calculateMinCost(i-1, colorSeq, reqTime, memo, colorSeq[i], max(reqTime[i], prevTime)) + min(reqTime[i], prevTime);
        else 
            return memo[i] = calculateMinCost(i-1, colorSeq, reqTime, memo, colorSeq[i], reqTime[i]);
        
    }
    
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> dp(n, -1);
        return calculateMinCost(n - 1, colors, neededTime, dp, 'A', neededTime[n - 1]);
    }
};