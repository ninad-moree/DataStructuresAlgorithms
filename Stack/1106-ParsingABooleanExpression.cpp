/*
    A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
    't' that evaluates to true. 'f' that evaluates to false.
    '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
    '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    Given a string expression that represents a boolean expression, return the evaluation of that expression.
    It is guaranteed that the given expression is valid and follows the given rules.

    Example 1:
    Input: expression = "&(|(f))"
    Output: false
    Explanation: 
    First, evaluate |(f) --> f. The expression is now "&(f)".
    Then, evaluate &(f) --> f. The expression is now "f".
    Finally, return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',') 
                continue; 
            else if (c == ')') {
                vector<char> subExpr;

                while (st.top() != '(') {
                    subExpr.push_back(st.top());
                    st.pop();
                }
                st.pop(); 
                
                char op = st.top();
                st.pop(); 
                
                if (op == '!') 
                    st.push(subExpr[0] == 'f' ? 't' : 'f');
                else if (op == '&') {
                    bool result = true;
                    for (char ch : subExpr) {
                        if (ch == 'f') {
                            result = false;
                            break;
                        }
                    }
                    st.push(result ? 't' : 'f');
                } else if (op == '|') {
                    bool result = false;
                    for (char ch : subExpr) {
                        if (ch == 't') {
                            result = true;
                            break;
                        }
                    }
                    st.push(result ? 't' : 'f');
                }
            } else 
                st.push(c);
        }
    
        return st.top() == 't';
    }
};