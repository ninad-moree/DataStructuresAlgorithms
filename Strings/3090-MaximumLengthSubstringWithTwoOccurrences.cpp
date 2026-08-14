/*
    Given a string s, return the maximum length of a  substring such that it contains at most two occurrences of each character.
 
    Example 1:
    Input: s = "bcbbbcba"
    Output: 4
    Explanation: The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int j = 0;
        int len = 0;

        unordered_map<char, int> mp;

        while(j < s.size()) {
            mp[s[j]]++;

            while(mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }

            len = max(len, j - i + 1);
            j++;
        }

        return len;
    }
};