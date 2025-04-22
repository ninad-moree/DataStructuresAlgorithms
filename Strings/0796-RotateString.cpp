/*
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. A shift on s consists of moving the 
    leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.

    Example 1:
    Input: s = "abcde", goal = "cdeab"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n != m)
            return false;

        goal += goal;

        for(int i=0; i<goal.size() - n + 1; i++) {
            if(goal.substr(i, n) == s)
                return true;
        }

        return false;
    }
};