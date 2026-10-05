/*
    You are given an integer n and a string s of length n consisting of digits. The dial contains the digits 0 through 9 in order and is circular, so 0 and 9 are adjacent. The 
    pointer initially points to 0. To dial each digit of s in order, rotate the pointer until it points to that digit. Each rotation moves the pointer to an adjacent digit, and
    you may rotate in either direction. Dialing a digit that the pointer already points to requires no rotations. Before dialing, you may perform the following operation at 
    most once: Choose an index k such that 0 <= k < n and reverse the suffix s[k..n - 1]. Return the minimum total number of rotations needed to dial the string after optimally
    choosing whether to perform the operation and which suffix to reverse.

    Example 1:
    Input: n = 4, s = "1502"
    Output: 9
    Explanation: Reverse the suffix starting at k = 1 to obtain "1205", then dial it. The total is 1 + 1 + 2 + 5 = 9, which is the minimum total number of rotations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        int ans = dist(0, s[0] - '0');

        for(int i = 1; i < n; i++) 
            ans += dist(s[i - 1] - '0', s[i] - '0');

        int original = ans;

        // Reverse the suffix starting at index k
        for(int k = 0; k < n; k++) {
            int cost = original;

            if(k == 0) {
                // 0 -> s[0] becomes 0 -> s[n-1]
                cost -= dist(0, s[0] - '0');
                cost += dist(0, s[n - 1] - '0');
            } else {
                // s[k-1] -> s[k] becomes s[k-1] -> s[n-1]
                cost -= dist(s[k - 1] - '0', s[k] - '0');
                cost += dist(s[k - 1] - '0', s[n - 1] - '0');
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};