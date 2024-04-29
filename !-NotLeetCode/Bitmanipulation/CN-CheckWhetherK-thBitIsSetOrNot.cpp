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
    string bits = "";

    int temp = n;
    while(temp) {
        int i = temp%2;
        string str = to_string(i);
        bits += str[0];

        temp = temp/2;
    }

    reverse(bits.begin(), bits.end());

    int len = bits.size();

    int idx = len-k;

    return bits[idx] == '1' ? true : false;
}