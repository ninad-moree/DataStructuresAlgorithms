/*
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

    Example 1:
    Input: s = "bcabc"
    Output: "abc"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, -1);
        for(int i=0; i<s.size(); i++)
            lastIdx[s[i] - 'a'] = i;

        vector<bool> inStack(26, 0);
        string stack = "";

        for(int i=0; i<s.size(); i++) {
            char ch = s[i];

            // character is already used
            if(inStack[ch - 'a'])
                continue;

            // if last element in  stack is greater than curr character, we remove the last element
            // also we check lastIdx[stack.back()] --> this implies the last Character will appear later in the string
            while(!stack.empty() && stack.back() > ch && lastIdx[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }

            stack.push_back(ch);
            inStack[ch - 'a'] = 1;
        }

        return stack;
    }
};