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
        if(n==0) 
            return 1;
        if(n==1) 
            return x;

        if(n>0) {
            if(n%2 == 0) 
                return myPow(x*x, n/2);
            else 
                return x*myPow(x*x, n/2);
        }
        else {
            n = abs(n);
            if(n%2 == 0) 
                return 1/(myPow(x*x, n/2));
            else 
                return 1/(x*(myPow(x*x, n/2)));
        }
    }
};