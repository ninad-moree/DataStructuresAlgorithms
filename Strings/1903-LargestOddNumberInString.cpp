/*
    You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, 
    or an empty string "" if no odd integer exists. A substring is a contiguous sequence of characters within a string.

    Example 1:
    Input: num = "52"
    Output: "5"
    Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";

        for(int i=num.size(); i>=0; i--) {
            char c = num[i];
            int n = c - '0';

            if(n%2 == 1)
                return num.substr(0, i+1);
        }

        return "";
    }
};