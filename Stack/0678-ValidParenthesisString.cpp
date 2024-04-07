/*
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
    The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Example 1:
    Input: s = "(*))"
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> starStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                openStack.push(i);
            else if (s[i] == '*')
                starStack.push(i);
            else {
                if (!openStack.empty())
                    openStack.pop();
                else if (!starStack.empty())
                    starStack.pop();
                else
                    return false;
            }
        }

        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() > starStack.top())
                return false;
            openStack.pop();
            starStack.pop();
        }

        return openStack.empty();
    }
};