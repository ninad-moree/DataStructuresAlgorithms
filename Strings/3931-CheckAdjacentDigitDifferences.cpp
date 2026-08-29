/*
    You are given a string s consisting of digits. Return true if the absolute difference between every pair of adjacent digits is at most 2, otherwise return false.
    The absolute difference between a and b is defined as abs(a - b).

    Example 1:
    Input: s = "132"
    Output: true
    Explanation: The absolute difference between digits at s[0] and s[1] is abs(1 - 3) = 2. The absolute difference between digits at s[1] and s[2] is abs(3 - 2) = 1.
    Since both differences are at most 2, the answer is true.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i=1; i<s.size(); i++) {
            int d1 = s[i] - '0';
            int d2 = s[i-1] - '0';

            if(abs(d1 - d2) > 2)
                return false;
        }

        return true;
    }
};