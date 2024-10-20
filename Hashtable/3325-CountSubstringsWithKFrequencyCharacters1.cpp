/*
    Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
    A substring is a contiguous non-empty sequence of characters within a string.

    Example 1:
    Input: s = "abacb", k = 2
    Output: 4
    Explanation:
    The valid substrings are:
    "aba" (character 'a' appears 2 times).
    "abac" (character 'a' appears 2 times).
    "abacb" (character 'a' appears 2 times).
    "bacb" (character 'b' appears 2 times).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;

        int left = 0;
        unordered_map<char, int> mp;

        for(int r=0; r<s.size(); r++) {
            mp[s[r]]++;

            while(mp[s[r]] == k) {
                mp[s[left]]--;
                left++;
            }

            ans += left;
        }

        return ans;
    }
};