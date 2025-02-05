/*
    You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily 
    different) and swap the characters at these indices. Return true if it is possible to make both strings equal by performing at most one string
    swap on exactly one of the strings. Otherwise, return false.

    Example 1:
    Input: s1 = "bank", s2 = "kanb"
    Output: true
    Explanation: For example, swap the first character with the last character of s2 to make "bank".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;

        if(s1.size() != s2.size())
            return false;

        vector<int> diff;

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                diff.push_back(i);
                if(diff.size() > 2)
                    return false;
            }
        }

        if(diff.size() != 2)
            return false;

        if(s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]])
            return true;
        return false;
    }
};