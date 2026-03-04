/*
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation
    at most k times. Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:
    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        vector<int> mp(26, 0);

        while(r < s.size()) {
            mp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mp[s[r] - 'A']);

            int currLen = r - l + 1;

            if(currLen - maxFreq> k) {
                mp[s[l] - 'A']--;
                l++;
            }

            if(currLen - maxFreq <= k)
                maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};