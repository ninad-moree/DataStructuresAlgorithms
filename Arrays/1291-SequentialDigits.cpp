/*
    An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
    Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

    Example 1:
    Input: low = 100, high = 300
    Output: [123,234]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int> ans;

        for (int digit = 1; digit <= 9; ++digit) {
            int num = digit;
            for (int nextDigit = digit + 1; nextDigit <= 9; ++nextDigit) {
                num = num * 10 + nextDigit;
                if (num >= low && num <= high) 
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};