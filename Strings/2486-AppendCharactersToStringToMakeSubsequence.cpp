/*
    You are given two strings s and t consisting of only lowercase English letters.
    Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

    Example 1:
    Input: s = "coaching", t = "coding"
    Output: 4
    Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
    Now, t is a subsequence of s ("coachingding").
    It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        while(i<s.size() && j<t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else
                i++;
        }

        return t.size()-j;
    }
};