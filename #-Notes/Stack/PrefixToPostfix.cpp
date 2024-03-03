#include <iostream>
#include <stack>
#include <bits/stdc++.h>
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

string preToPost(string s) {
    // Write Your Code Here
    reverse(s.begin(), s.end());
    stack<string> st;

    for(int i=0; i<s.size(); i++) {
        string curr =  "";
        curr += s[i];

        if(isOperator(s[i]) == false) 
            st.push(curr);
        else {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            st.push(op1+op2+curr);
        }
    }

    return st.top();
}