/*
    Given an integer n, return true if it is a power of two. Otherwise, return false.
    An integer n is a power of two, if there exists an integer x such that n == 2x.

    Example 1:
    Input: n = 1
    Output: true

    Example 2:
    Input: n = 16
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>=1) {
            if(n%2==0) {
                n=n/2;
            }
            else 
                break;
        }
        if(n==1) 
            return true;
        return false;
    }
};