/*
    You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

    Example 1:
    Input: n = 10, t = 2
    Output: 10
    Explanation: The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitProduct(string s) {
        int ans = 1;

        for(auto i : s) {
            int n = i - '0';
            ans *= n;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {
        int ans = 0;

        for(int i=n; i<=100; i++) {
            int num = i;
            string s = to_string(i);

            int prod = digitProduct(s);

            if(prod % t == 0) {
                ans = num;
                break;
            }
        }

        return ans;
    }
};