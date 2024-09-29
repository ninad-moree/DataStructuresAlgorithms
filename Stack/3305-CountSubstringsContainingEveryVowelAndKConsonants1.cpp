/*
    You are given a string word and a non-negative integer k. Return the total number of substrings of word that contain every vowel 
    ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

    Example 1:
    Input: word = "aeioqq", k = 1
    Output: 0
    Explanation: There is no substring with every vowel.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowelCount(unordered_map<char, int>& mp) {
        return mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0;
    }
    
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        int n = word.size();

        unordered_map<char, bool> vowels = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};

        for (int i = 0; i < n; i++) {
            int conso = 0;
            unordered_map<char, int> mp;

            for (int j = i; j < n; j++) {
                char ch = word[j];

                if (vowels[ch]) 
                    mp[ch]++;
                else 
                    conso++;
                
                if (conso > k)
                    break;
            
                if (isVowelCount(mp) && conso == k) 
                    ans++;
            }
        }

        return ans;
    }
};