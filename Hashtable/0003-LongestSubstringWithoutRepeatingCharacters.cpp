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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int ans = 0;

        while(r < s.size()) {
            mp[s[r]]++;

            if(mp[s[r]] > 1) {
                while(mp[s[r]] > 1) {
                    mp[s[l]]--;
                    l++;
                }
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};