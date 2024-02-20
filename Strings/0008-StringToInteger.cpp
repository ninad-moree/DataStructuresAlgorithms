/*
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

    Example 1:
    Input: s = "42"
    Output: 42
    Explanation: The underlined characters are what is read in, the caret is the current reader position.
    Step 1: "42" (no characters read because there is no leading whitespace)
            ^
    Step 2: "42" (no characters read because there is neither a '-' nor '+')
            ^
    Step 3: "42" ("42" is read in)
            ^
    The parsed integer is 42.
    Since 42 is in the range [-231, 231 - 1], the final result is 42.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();

        while(s[i] == ' ') 
            i++;

        int pos = 0, neg = 0;

        if(s[i] == '+') {
            pos++;
            i++;
        }
        if(s[i] == '-') {
            neg++;
            i++;
        }

        double ans = 0;

        while(i<n && s[i]>='0' && s[i]<='9') {
            ans = ans*10 + (s[i]-'0');
            i++;
        }

        if(neg>0) 
            ans = -ans;
        if(pos>0 && neg>0) 
            return 0;
        if(ans>INT_MAX) 
            ans = INT_MAX;
        if(ans<INT_MIN) 
            ans = INT_MIN;

        return int(ans);
    }
};