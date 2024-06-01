/*
    Given a string word, compress it using the following algorithm:
    Begin with an empty string comp. While word is not empty, use the following operation:
    Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
    Append the length of the prefix followed by c to comp.
    Return the string comp.

    Example 1:
    Input: word = "abcde"
    Output: "1a1b1c1d1e"
    Explanation:
    Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
    For each prefix, append "1" followed by the character to comp.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        
        char c = word[0];
        int i = 0;
        int cnt = 0;

        while(word[i]) {
            while(word[i] == c) {
                cnt++;
                if(cnt == 9) {
                    comp += '9';
                    comp += c;
                    cnt = 0;
                }
                i++;
            }

            if(cnt != 0) {
                comp += to_string(cnt);
                comp += c;
            }

            cnt = 0;
            c = word[i];
        }

        return comp;
    }
};