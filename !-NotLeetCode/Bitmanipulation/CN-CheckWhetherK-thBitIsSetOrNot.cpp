/*
    Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.

    Example:
    Input: ‘N’ = 5, ‘K’ = 1
    Output: YES
    5 in binary can be written as 101 and as we can see a first bit from the right of 5 is set so the answer is 'YES'.
*/

#include<bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k) {
    // Write your code here.
    int mask = 1 << (k-1);
    int res = n & mask;

    return res != 0;
}