/*
    Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
    '#' means a backspace character.
    Note that after backspacing an empty text, the text will continue empty.

    Example 1:
    Input: s = "ab#c", t = "ad#c"
    Output: true
    Explanation: Both s and t become "ac".
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for(auto i : s) {
            if(i != '#')
                s1.push(i);
            else if(!s1.empty())
                s1.pop();
        }

        for(auto i : t) {
            if(i != '#')
                s2.push(i);
            else if(!s2.empty())
                s2.pop();
        }
        
        return s1 == s2;
    }
};