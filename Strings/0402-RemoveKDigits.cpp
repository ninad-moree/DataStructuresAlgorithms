/*
    Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

    Example 1:
    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";

        string result = "";

        for (char digit : num) {
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0')
            nonZeroIndex++;
            
        if (nonZeroIndex == result.size())
            return "0";
        else
            return result.substr(nonZeroIndex);
    }
};