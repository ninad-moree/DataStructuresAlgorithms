/*
    Two strings are considered close if you can attain one from the other using the following operations:
    Operation 1: Swap any two existing characters.
                    For example, abcde -> aecdb
    Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
                    For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
    Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

    Example 1:
    Input: word1 = "abc", word2 = "bca"
    Output: true
    Explanation: You can attain word2 from word1 in 2 operations.
    Apply Operation 1: "abc" -> "acb"
    Apply Operation 1: "acb" -> "bca"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool secondFunction(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        unordered_map<char, int> freq1, freq2;
        unordered_set<char> set1, set2;

        for (char c : word1) {
            freq1[c]++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c]++;
            set2.insert(c);
        }

        if (set1 != set2)
            return false;

        unordered_map<int, int> freqCount1, freqCount2;

        for (const auto& entry : freq1)
            freqCount1[entry.second]++;

        for (const auto& entry : freq2)
            freqCount2[entry.second]++;

        return freqCount1 == freqCount2;
    }

    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : word1) 
            freq1[ch - 'a']++;

        for (char ch : word2) 
            freq2[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) 
                return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) 
                return false;
        }

        return true;
    }
};