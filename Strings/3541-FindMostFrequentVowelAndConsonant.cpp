/*
    You are given a string s consisting of lowercase English letters ('a' to 'z'). Your task is to:
    Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency. Find the consonant with the maximum frequency.
    Return the sum of the two frequencies.
    If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the 
    string, consider their frequency as 0. The frequency of a letter x is the number of times it occurs in the string.

    Example 1:
    Input: s = "successes"
    Output: 6
    Explanation:
    The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
    The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
    The output is 2 + 4 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int mv = 0, mc = 0;

        for(auto i : s) {
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                mp[i]++;
                mv = max(mv, mp[i]);
            } else {
                mp[i]++;
                mc = max(mc, mp[i]);
            }
        }

        return mv + mc;
    }
};