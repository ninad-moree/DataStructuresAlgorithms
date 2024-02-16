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

string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> st;
	
	for(int i=s.size()-1; i>=0; i--) {
		if(isOperator(s[i])) {
			string op1 = st.top();
			st.pop();

			string op2 = st.top();
			st.pop();

			string exp = "(" + op1 + s[i] + op2 + ")";

			st.push(exp);
		} else {
            // creates string with lenght 1 and character s[i]
			st.push(string(1, s[i])); 
		}
	}

	return st.top();
}