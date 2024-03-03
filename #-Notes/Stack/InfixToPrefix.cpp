#include <iostream>
#include <stack>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; 
}

string infixToPrefix(string exp) {
    stack<char> st;
    string ans = "";

    for (auto i : exp) {
        if (isalnum(i)) {
            ans += i;
        } else if (i == ')') {
            st.push(i);
        } else if (i == '(') {
            while (!st.empty() && st.top() != ')') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the ')'
        } else if (isOperator(i)) {
            while (!st.empty() && isOperator(st.top()) && precedence(st.top()) > precedence(i)) {
                ans += st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}