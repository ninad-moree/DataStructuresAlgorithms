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

string postToInfix(string postfix) {
    // Write your code here.
    stack<string> st;

    for(int i=0;i<postfix.size();i++) {
        if(isOperator(postfix[i])) {
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string temp = '(' + op1 + postfix[i] + op2 + ')';
            st.push(temp);
        }
        else 
            st.push(string(1, postfix[i])); 
    }

    return st.top();
}