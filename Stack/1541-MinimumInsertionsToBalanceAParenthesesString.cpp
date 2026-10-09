/*
    Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if: Any left parenthesis '(' must have a corresponding two 
    consecutive right parenthesis '))'. Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'. In other words, we treat '(' as an opening 
    parenthesis and '))' as a closing parenthesis. For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced. You can insert the 
    characters '(' and ')' at any position of the string to balance it if needed. Return the minimum number of insertions needed to make s balanced.

    Example 1:
    Input: s = "(()))"
    Output: 1
    Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is 
    balanced.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<char> st;

        int i = 0;

        while(i < s.size()) {
            if(s[i] == '(') {
                st.push(s[i]);
                i++;
            }
            else {
                if(i + 1 < s.size()) {
                    char ch1 = s[i];
                    char ch2 = s[i+1];

                    if(ch1 == ')' && ch2 == ')') {
                        if(!st.empty())
                            st.pop();
                        else
                            ans++;
                        i += 2;
                    } else{
                        ans++;
                        if(!st.empty())
                            st.pop();
                        else
                            ans++;
                        i++;
                    }
                } else {
                    ans++;
                    if(!st.empty())
                        st.pop();
                    else
                        ans++;
                    i++;
                }
            }
        }

        ans += (st.size() * 2);

        return ans;
    }
};