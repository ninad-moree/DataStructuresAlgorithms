/*
    You are given two strings of the same length s and t. In one step you can choose any character of t 
    and replace it with another character.
    Return the minimum number of steps to make t an anagram of s.
    An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

    Example 1:
    Input: s = "bab", t = "aba"
    Output: 1
    Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        if (s.length() != t.length())
            return -1;

        unordered_map<char, int> freqS, freqT;

        for (char ch : s) 
            freqS[ch]++;
        
        for (char ch : t)
            freqT[ch]++;
        int steps = 0;
        for (const auto& pair : freqS) {
            char ch = pair.first;
            int countS = pair.second;
            int countT = freqT[ch];

            if (countS > countT) 
                steps += (countS - countT);
        }

        return steps;
    }
};