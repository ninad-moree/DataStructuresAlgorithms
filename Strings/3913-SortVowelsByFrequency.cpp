/*
    You are given a string s consisting of lowercase English characters. Rearrange only the vowels in the string so that they appear in non-increasing order of their frequency.
    If multiple vowels have the same frequency, order them by the position of their first occurrence in s. Return the modified string. Vowels are 'a', 'e', 'i', 'o', and 'u'.
    The frequency of a letter is the number of times it occurs in the string.

    Example 1:
    Input: s = "leetcode"
    Output: "leetcedo"
    Explanation:​​​​​​​ Vowels in the string are ['e', 'e', 'o', 'e'] with frequencies: e = 3, o = 1. Sorting in non-increasing order of frequency and placing them back into the vowel
    positions results in "leetcedo".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string ans = s;
        vector<pair<int, pair<int, char>>> vow; // {frequency, {firstIndex, vowel}}
        unordered_map<char, int> freq; // {char, frequency}
        unordered_map<char, int> first; // {char, firstIndex}

        for(int i=0; i<s.size(); i++) {
            char c = s[i];

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                freq[c]++;

                if (!first.count(c)) // get 1st occurance of the vowel
                    first[c] = i;
            }
        }

        for (char c : {'a', 'e', 'i', 'o', 'u'}) {
            if (freq[c] > 0) 
                vow.push_back({freq[c], {first[c], c}});
        }

        sort(vow.begin(), vow.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first)
                return a.first > b.first;   // frequency descending

            return a.second.first < b.second.first; // first index ascending
        });

        int idx = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == 'a' || c == 'e' || c == 'i' ||  c == 'o' || c == 'u') {
                s[i] = vow[idx].second.second;
                count++;

                if (count == vow[idx].first) {
                    idx++;
                    count = 0;
                }
            }
        }

        return s;
    }
};