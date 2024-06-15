/*
    You are given a string s. Your task is to remove all digits by doing this operation repeatedly:
    Delete the first digit and the closest non-digit character to its left.
    Return the resulting string after removing all digits.

    Example 1:
    Input: s = "abc"
    Output: "abc"
    Explanation:
    There is no digit in the string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z')
                st.push(s[i]);
            else 
                st.pop();
        }

        if(st.empty())
            return "";
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};