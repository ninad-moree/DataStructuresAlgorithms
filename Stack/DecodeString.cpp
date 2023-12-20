/*
    Given an encoded string, return its decoded string.
    The encoding rule is: k[encoded_string], where the encoded_string inside the square 
    brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
    You may assume that the input string is always valid; there are no extra white spaces, square 
    brackets are well-formed, etc. Furthermore, you may assume that the original data does not 
    contain any digits and that digits are only for those repeat numbers, k. For example, there 
    will not be input like 3a or 2[4].
    The test cases are generated so that the length of the output will never exceed 105.
    
    Example 1:
    Input: s = "3[a]2[bc]"
    Output: "aaabcbc"

    Example 2:
    Input: s = "3[a2[c]]"
    Output: "accaccacc"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;

        string currentStr = "";
        int count = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                count = count * 10 + (ch - '0'); 
            } else if (isalpha(ch)) {
                currentStr += ch; 
            } else if (ch == '[') {
                countStack.push(count); 
                strStack.push(currentStr);
                count = 0; 
                currentStr = ""; 
            } else if (ch == ']') {
                int k = countStack.top(); 
                countStack.pop();
                string decodedStr = strStack.top(); 
                strStack.pop();

                for (int i = 0; i < k; ++i) {
                    decodedStr += currentStr; 
                }

                currentStr = decodedStr; 
            }
        }

        return currentStr;
    }
};