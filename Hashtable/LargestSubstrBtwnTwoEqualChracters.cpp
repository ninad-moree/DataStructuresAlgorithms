/*
    Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. 
    If there is no such substring return -1.
    A substring is a contiguous sequence of characters within a string.

    Example 1:
    Input: s = "aa"
    Output: 0
    Explanation: The optimal substring here is an empty substring between the two 'a's.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> charIndex;
        int maxLen = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndex.find(s[i]) != charIndex.end())
                maxLen = max(maxLen, i - charIndex[s[i]] - 1);
            else
                charIndex[s[i]] = i;
        }

        return maxLen;
    }
};