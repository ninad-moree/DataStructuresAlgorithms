/*
    Given two strings s and t of lengths m and n respectively, return the minimum window 
    substring of s such that every character in t (including duplicates) is included in the 
    window. If there is no such substring, return the empty string "".
    The testcases will be generated such that the answer is unique.

    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mp;
        for(auto c : t) {
            mp[c]++;
        }

        int left = 0, right = 0;
        int cnt = t.size();

        int minStart = 0;
        int minLen = INT_MAX;

        while(right < s.size()) {
            if(mp[s[right]] > 0)
                cnt--;
            
            mp[s[right]]--;
            right++;

            while(cnt == 0) {
                if(right-left < minLen) {
                    minStart = left;
                    minLen = right - left;
                }

                mp[s[left]]++;
                if(mp[s[left]] > 0)
                    cnt++;
                left++;
            }
        }
        if (minLen != INT_MAX) {
            return s.substr(minStart, minLen);
        }
        return "";
    }
};