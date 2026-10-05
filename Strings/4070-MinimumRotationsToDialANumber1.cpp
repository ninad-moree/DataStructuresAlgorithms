/*
    You are given a string s of length 10 consisting of digits. The dial contains the digits 0 through 9 in order and is circular, so 0 and 9 are adjacent. The pointer initially
    points to 0. To dial each digit of s in order, rotate the pointer until it points to that digit. Each rotation moves the pointer to an adjacent digit, and you may rotate in
    either direction. Dialing a digit that the pointer already points to requires no rotations. Return the minimum total number of rotations needed to dial every digit of s.

    Example 1:
    Input: s = "0192837465"
    Output: 25
    Explanation: The total is 0 + 1 + 2 + 3 + 4 + 5 + 4 + 3 + 2 + 1 = 25, which is the minimum total number of rotations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRotations(string s) {
        int ans = min(s[0] - '0', 10 - (s[0] - '0'));

        for(int i=1; i<s.size(); i++) {
            int prev = s[i-1] - '0';
            int curr = s[i] - '0';

            ans += min(abs(curr - prev), 10 - abs(prev - curr));
        }

        return ans;
    }
};