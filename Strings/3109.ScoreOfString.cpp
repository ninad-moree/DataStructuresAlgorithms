/*
    You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
    Return the score of s.

    Example 1:
    Input: s = "hello"
    Output: 13
    Explanation:
    The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| +
     |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        
        for(int i=0; i<s.size()-1; i++) {
            ans += abs(s[i] - s[i+1]);
        }
        
        return ans;
    }
};