/*
    Given a string text, you want to use the characters of text to form as 
    many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number 
    of instances that can be formed.

    Example 1:
    Input: text = "nlaebolko"
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;

        for (char c : text) {
            freq[c]++;
        }

        int count = 0;
        while (true) {
            if (freq['b'] >= 1 && freq['a'] >= 1 && freq['l'] >= 2 && freq['o'] >= 2 && freq['n'] >= 1) {
                count++;
                freq['b']--;
                freq['a']--;
                freq['l'] -= 2;
                freq['o'] -= 2;
                freq['n']--;
            } else {
                break;
            }
        }

        return count;
    }
};