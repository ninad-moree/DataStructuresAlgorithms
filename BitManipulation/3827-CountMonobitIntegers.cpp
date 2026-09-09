/*
    You are given an integer n. An integer is called Monobit if all bits in its binary representation are the same. Return the count of Monobit integers in the range [0, n]

    Example 1:
    Input: n = 1
    Output: 2
    Explanation: The integers in the range [0, 1] have binary representations "0" and "1". Each representation consists of identical bits. Thus, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;

        long long x = 1;

        while (x <= n) {
            ans++;
            x = 2 * x + 1;
        }

        return ans;
    }
};