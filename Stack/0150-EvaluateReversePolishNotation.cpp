/*
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

    Evaluate the expression. Return an integer that represents the value of the expression.
    Note that:
        The valid operators are '+', '-', '*', and '/'.
        Each operand may be an integer or another expression.
        The division between two integers always truncates toward zero.
        There will not be any division by zero.
        The input represents a valid arithmetic expression in a reverse polish notation.
        The answer and all the intermediate calculations can be represented in a 32-bit integer.
    
    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOperator(const string& token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }

    int performOperation(int operand1, int operand2, const string& op) {
        if (op == "+") {
            return operand1 + operand2;
        } else if (op == "-") {
            return operand1 - operand2;
        } else if (op == "*") {
            return operand1 * operand2;
        } else if (op == "/") {
            return operand1 / operand2;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                int result = performOperation(operand1, operand2, token);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};