/*
    You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
    Return the number of special letters in word.

    Example 1:
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters in word are 'a', 'b', and 'c'.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> specialLetters;

        for (char c : word) {
            char lower = tolower(c);
            char upper = toupper(c);
            if (isalpha(c) && lower != upper && specialLetters.find(lower) == specialLetters.end()) {
                if (word.find(lower) != string::npos && word.find(upper) != string::npos) {
                    specialLetters.insert(lower);
                }
            }
        }

        return specialLetters.size();
    }
};