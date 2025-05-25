/*
    You are given an array of strings words. Each element of words consists of two lowercase English letters. Create the longest possible palindrome
    by selecting some elements from words and concatenating them in any order. Each element can be selected at most once. Return the length of the 
    longest palindrome that you can create. If it is impossible to create any palindrome, return 0. A palindrome is a string that reads the same 
    forward and backward.

    Example 1:
    Input: words = ["lc","cl","gg"]
    Output: 6
    Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto i : words)
            mp[i]++;

        int cnt = 0;
        int isPalindrome = 0;

        for(auto i : mp) {
            string s = i.first;
            int freq = i.second;

            reverse(s.begin(), s.end());

            if(i.first == s) {
                cnt += (freq / 2) * 4;
                if(freq % 2 == 1)
                    isPalindrome = 1;
            } else if (i.first < s && mp.count(s))
                cnt += min(freq, mp[s]) * 4;
        }

        return cnt + isPalindrome*2;
    }
};