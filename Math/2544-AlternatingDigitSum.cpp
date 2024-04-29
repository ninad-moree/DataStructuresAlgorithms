/*
    You are given a positive integer n. Each digit of n has a sign according to the following rules:
    The most significant digit is assigned a positive sign.
    Each other digit has an opposite sign to its adjacent digits.
    Return the sum of all digits with their corresponding sign.

    Example 1:
    Input: n = 521
    Output: 4
    Explanation: (+5) + (-2) + (+1) = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;

        string num = to_string(n);

        bool sign = true;
        for(int i=0; i<num.size(); i++) {
            char c = num[i];
            string s = "";
            s += c;
            
            int j = stoi(s);
            if(sign) 
                sum += j;
            else
                sum += (-1*j);
            
            sign = !sign;
        }

        return sum;
    }
};