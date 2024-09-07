/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

    Example 1:
    Input: s = "()"
    Output: true
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i : s) {
            if(i == '(' || i == '{' || i == '[') 
                st.push(i);
            else if(i == ')') {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            } else if(i == '}') {
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            } else if(i == ']') {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};