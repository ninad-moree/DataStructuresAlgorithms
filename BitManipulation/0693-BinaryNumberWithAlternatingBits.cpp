/*
    Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

    Example 1:
    Input: n = 5
    Output: true
    Explanation: The binary representation of 5 is: 101
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = n % 2;
        n = n/2;

        while(n) {
            if(curr == n%2)
                return false;
            curr = n % 2;
            n = n/2;
        }

        return true;
    }
};