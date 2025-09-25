/*
    Given two integers representing the numerator and denominator of a fraction, return the fraction in string format. If the fractional part is repeating,
    enclose the repeating part in parentheses. If multiple answers are possible, return any of them. It is guaranteed that the length of the answer string
    is less than 104 for all the given inputs.

    Example 1:
    Input: numerator = 1, denominator = 2
    Output: "0.5"
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        string ans;

        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ans += "-";

        long long num = llabs(numerator);
        long long den = llabs(denominator);

        ans += to_string(num / den);
        long long rem = num % den;

        if(rem == 0)
            return ans;

        ans += ".";

        unordered_map<long long, int> mp;
        while(rem) {
            if(mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem = rem % den;
        }

        return ans;
    }
};