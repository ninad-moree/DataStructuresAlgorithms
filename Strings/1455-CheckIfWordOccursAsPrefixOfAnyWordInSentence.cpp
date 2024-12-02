/*
    Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in 
    sentence. Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than 
    one word, return the index of the first word (minimum index). If there is no such word return -1. A prefix of a string s is any leading contiguous
    substring of s.

    Example 1:
    Input: sentence = "i love eating burger", searchWord = "burg"
    Output: 4
    Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int m = searchWord.size();
        int cnt = 0;

        stringstream ss(sentence);
        string token;

        while(ss >> token) {
            cnt++;
            if(token.size() >= m && token.substr(0, m) == searchWord)
                return cnt;
        }
        
        return -1;
    }
};