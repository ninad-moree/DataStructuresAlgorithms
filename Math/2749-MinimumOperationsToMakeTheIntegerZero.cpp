/*
    You are given two integers num1 and num2. In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1. Return 
    the integer denoting the minimum number of operations needed to make num1 equal to 0. If it is impossible to make num1 equal to 0, return -1.

    Example 1:
    Input: num1 = 3, num2 = -2
    Output: 3
    Explanation: We can make 3 equal to 0 with the following operations:
    - We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
    - We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
    - We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
    It can be proven, that 3 is the minimum number of operations that we need to perform.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = 1;

        while(true) {
            long long x = num1 - static_cast<long long>(num2) * ans;

            if(x < ans)
                return -1;
            
            if(ans >= __builtin_popcountll(x))
                return ans;
            
            ans++;
        }
    }
};