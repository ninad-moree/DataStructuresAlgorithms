/*
    Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence 
    of ch (inclusive). If the character ch does not exist in word, do nothing. For example, if word = "abcdefd" and ch = "d", then you should reverse 
    the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd". Return the resulting string.

    Example 1:
    Input: word = "abcdefd", ch = "d"
    Output: "dcbaefd"
    Explanation: The first occurrence of "d" is at index 3. 
    Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        for(int i=0; i<word.size(); i++) {
            if(word[i] == ch) {
                idx = i;
                break;
            }
        }

        if(idx == -1)
            return word;
        
        string ans = "";

        for(int i = idx; i>=0; i--) 
            ans += word[i];
        
        for(int i= idx+1; i<word.size(); i++)
            ans += word[i];

        return ans;
    }
};