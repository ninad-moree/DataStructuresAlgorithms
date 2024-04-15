/*
    You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
    Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
 
    Example 1:
    Input: num = 11891
    Output: 99009
    Explanation: 
    To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
    To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
    The difference between these two numbers is 99009.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);

        int idx = 0;
        int i = 0;
        
        for(i=0; i<s1.size(); i++) {
            if(s1[i] != '9') {
                idx = i;
                break;
            }
        }

        if(i == s1.size())
            return num;
        
        char n = s1[idx];
        char c = s1[0];

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == n)
                s1[i] = '9';
            if(s2[i] == c) 
                s2[i] = '0';
        }

        int n1 = stoi(s1);
        int n2 = stoi(s2);

        return n1-n2;
    }
};