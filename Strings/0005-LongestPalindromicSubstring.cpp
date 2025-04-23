/*
    Given a string s, return the longest palindromi substring in s.

    Example 1:
    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string s, int left, int right) {
        while(left >= 0 && right<s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)
            return s;

        string longest = s.substr(0, 1);

        for(int i=0; i<s.size(); i++) {
            string p1 = solve(s, i, i);
            if(p1.size() > longest.size())
                longest = p1;

            string p2 = solve(s, i, i+1);
            if(p2.size() > longest.size())
                longest = p2;
        }

        return longest;
    }
};