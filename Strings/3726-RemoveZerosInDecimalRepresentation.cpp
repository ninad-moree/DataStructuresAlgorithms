/*
    You are given a positive integer n. Return the integer obtained by removing all zeros from the decimal representation of n.

    Example 1:
    Input: n = 1020030
    Output: 123
    Explanation: After removing all zeros from 1020030, we get 123.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string s2 = "";

        for(auto i : s) {
            if(i != '0')
                s2 += i;
        }

        long long ans = stoll(s2);
        return ans;
    }
};