/*
    You are given a string s that consists of lower case English letters and brackets. Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.

    Example 1:
    Input: s = "(abcd)"
    Output: "dcba"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        string res = "";
        stack<char> st;

        int i = 0;

        while(i < s.size()) {
            if(s[i] != ')'){
                st.push(s[i]);
                i++;
            } else {
                while(st.top() != '(') {
                    res += st.top();
                    st.pop();
                }

                st.pop();

                for(auto i : res)
                    st.push(i);

                res = "";
                i++;
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};