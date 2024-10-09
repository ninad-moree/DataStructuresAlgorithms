/*
    A parentheses string is valid if and only if:
    It can be written as AB(A concatenated with B), where A and B are valid strings, or It can be written as (A), where A is a valid string.
    You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
    Return the minimum number of moves required to make s valid.

    Example 1:
    Input: s = "())"
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;

        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(')
                st.push(s[i]);
            else {
                if(!st.empty())
                    st.pop();
                else
                    ans++;
            }
        }

        ans += st.size();
        return ans;
    }
};