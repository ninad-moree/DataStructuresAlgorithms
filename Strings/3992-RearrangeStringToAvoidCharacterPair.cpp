/*
    You are given a string s and two distinct lowercase English letters x and y. Rearrange the characters of s to construct a new string t such that:
    t is a permutation of s. Every occurrence of y appears before every occurrence of x in t. Return any valid string t.

    Example 1:
    Input: s = "aabc", x = "a", y = "c"
    Output: "cbaa"
    Explanation: The string "cbaa" is a permutation of "aabc", and every occurrence of 'c' appears before every occurrence of 'a'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans = "";

        for(auto i : s) {
            if(i == y)
                ans.insert(ans.begin(), y);
            else
                ans.push_back(i);
        }

        return ans;
    }
};