/*
    Given a string s, find the length of the longest substring without repeating characters.

    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < s.size()) {
            if (mp.find(s[j]) == mp.end()) {
                mp[s[j]] = 1;
                ans = std::max(ans, j - i + 1);
                j++;
            } else {
                mp.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};