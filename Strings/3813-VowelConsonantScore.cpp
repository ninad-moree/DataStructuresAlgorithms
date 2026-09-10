/*
    You are given a string s consisting of lowercase English letters, spaces, and digits. Let v be the number of vowels in s and c be the number of consonants in s. A vowel is 
    one of the letters 'a', 'e', 'i', 'o', or 'u', while any other letter in the English alphabet is considered a consonant. The score of the string s is defined as follows:
    If c > 0, the score = floor(v / c) where floor denotes rounding down to the nearest integer. Otherwise, the score = 0. Return an integer denoting the score of the string.

    Example 1:
    Input: s = "cooear"
    Output: 2
    Explanation: The string s = "cooear" contains v = 4 vowels ('o', 'o', 'e', 'a') and c = 2 consonants ('c', 'r'). The score is floor(v / c) = floor(4 / 2) = 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        int v = 0;
        int c = 0;

        for(auto ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                v++;
            else if(ch >= 'a' && ch <= 'z')
                c++;
        }

        if(c == 0)
            return 0;
        return v / c;
    }
};