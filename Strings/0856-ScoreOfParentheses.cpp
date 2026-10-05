/*
    Given a balanced parentheses string s, return the score of the string. The score of a balanced parentheses string is based on the following rule:
    "()" has score 1. AB has score A + B, where A and B are balanced parentheses strings. (A) has score 2 * A, where A is a balanced parentheses string.

    Example 1:
    Input: s = "()"
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int score = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(')
                depth++;
            else {
                depth--;

                if(s[i - 1] == '(')
                    score += 1 << depth; // 2^depth
            }
        }

        return score;
    }
};