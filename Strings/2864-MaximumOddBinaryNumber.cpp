/*
    You are given a binary string s that contains at least one '1'.
    You have to rearrange the bits in such a way that the resulting binary number is the maximum odd 
    binary number that can be created from this combination.
    Return a string representing the maximum odd binary number that can be created from the given combination.
    Note that the resulting string can have leading zeros.

    Example 1:
    Input: s = "010"
    Output: "001"
    Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        string ans = s;

        for (int i = 0; i < s.size(); i++)
            ans[i] = '0';

        int cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt1++;
        }

        if (cnt1 == 1)
            ans[s.size() - 1] = '1';

        if (cnt1 > 1) {
            int cnt = cnt1 - 1;
            int i = 0;
            while (cnt > 0) {
                ans[i] = '1';
                cnt--;
                i++;
            }
            ans[s.size() - 1] = '1';
        }

        return ans;
    }
};