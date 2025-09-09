/*
    No-Zero integer is a positive integer that does not contain any 0 in its decimal representation. Given an integer n, return a list of two integers
    [a, b] where: a and b are No-Zero integers. a + b = n
    The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

    Example 1:
    Input: n = 2
    Output: [1,1]
    Explanation: Let a = 1 and b = 1. Both a and b are no-zero integers, and a + b = 2 = n.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasZero(int a) {
        while(a > 0) {
            if(a % 10 == 0)
                return false;
            a = a/10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<n; i++) {
            int j = n - i;

            if(hasZero(i) && hasZero(j))
                return {i, j};
        }

        return {};
    }
};