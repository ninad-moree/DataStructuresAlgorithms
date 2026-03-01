/*
    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        int m = n;
        long long N = n;
        N = abs(N);

        double ans = 1;

        while(N > 0) {
            if(N % 2 == 1) {
                ans = ans * x;
                N = N - 1;
            } else {
                N = N / 2;
                x = x * x;
            }
        }

        if(m < 0)
            ans = 1.0 /  ans;

        return ans;
    }
};