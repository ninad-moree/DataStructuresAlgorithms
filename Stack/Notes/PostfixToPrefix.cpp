#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char x) {
  switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
      return true;
  }
  return false;
}

string postfixToPrefix(string &s) {
  stack<string> st;

  for (int i = 0; i < s.size(); i++) {
    if (isOperator(s[i]) == false) {
      st.push(string(1, s[i])); 
    } else {
      string op1 = st.top();
      st.pop();

      string op2 = st.top();
      st.pop();

      st.push(s[i] + op2 + op1);
    }
  }

  return st.top();
}