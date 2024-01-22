/*
    You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
    In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and 
    delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.
    Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary 
    order will lead to the same result.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters 
    exactly once. For example, "dacb" is an anagram of "abdc".

    Example 1:
    Input: words = ["abba","baba","bbaa","cd","cd"]
    Output: ["abba","cd"]
    Explanation:
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=0;i<words.size()-1;i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            if(s1 == s2) {
                words.erase(words.begin() + i+1);
                i--;
            }
        }
        
        return words;
    }
};