/*
    You are given an integer n. Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0. Let sum be 
    the sum of digits in x. Return an integer representing the value of x * sum.

    Example 1:
    Input: n = 10203004
    Output: 12340
    Explanation: The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234. The sum of digits is sum = 1 + 2 + 3 + 4 = 10. Therefore, the answer is x * sum = 1234 * 10 = 12340.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        string res = "";

        for(int i=0; i<str.size(); i++) {
            if(str[i] != '0')
                res += str[i];
        }

        if(res.size() == 0)
            return 0;

        long long num = stoll(res);

        long long sum = 0;
        long long temp = num;

        while(temp > 0) {
            int digit = temp%10;
            temp = temp/10;
            sum += digit;
        }

        return sum * num;
    }
};