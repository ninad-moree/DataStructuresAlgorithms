/*
    You are given a string s and a character c. Return the total number of substrings of s that start and end with c.

    Example 1:
    Input: s = "abada", c = "a"
    Output: 6
    Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long freq = 0;

        for(auto i : s) {
            if(i == c)
                freq++;
        }

        freq = (freq * (freq+1)) / 2;

        return freq;
    }
};