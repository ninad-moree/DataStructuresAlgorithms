/*
    Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings 
    (i.e. left substring and right substring).
    The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

    Example 1:
    Input: s = "011101"
    Output: 5 
    Explanation: 
    All possible ways of splitting s into two non-empty substrings are:
    left = "0" and right = "11101", score = 1 + 4 = 5 
    left = "01" and right = "1101", score = 1 + 3 = 4 
    left = "011" and right = "101", score = 1 + 2 = 3 
    left = "0111" and right = "01", score = 1 + 1 = 2 
    left = "01110" and right = "1", score = 2 + 1 = 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int max_score = 0;
        int zeros_count = 0;
        int ones_count = 0;

        for (char ch : s) {
            if (ch == '1') {
                ones_count++;
            }
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                zeros_count++;
            } else {
                ones_count--;
            }

            int current_score = zeros_count + ones_count;
            if (current_score > max_score) {
                max_score = current_score;
            }
        }

        return max_score;
    }
};