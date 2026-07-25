/*
    You are given a positive integer n. Return the maximum product of any two digits in n. Note: You may use the same digit twice if it appears more than once in n.

    Example 1:
    Input: n = 31
    Output: 3
    Explanation: The digits of n are [3, 1]. The possible products of any two digits are: 3 * 1 = 3. The maximum product is 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        int second = 0;

        while(n) {
            int rem = n % 10;
            n = n/10;

            if(rem > first) {
                second = first;
                first = rem;
            } else if(rem > second)
                second = rem;
        }

        return first * second;
    }
};