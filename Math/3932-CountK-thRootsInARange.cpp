/*
    You are given three integers l, r, and k. An integer y is said to be a perfect kth power if there exists an integer x such that y = x^k. Return the number of integers y in 
    the range [l, r] (inclusive) that are perfect kth powers.

    Example 1:
    Input: l = 1, r = 9, k = 3
    Output: 2
    Explanation: The perfect cubes in the range [1, 9] are: 1 = 13, 8 = 23. Hence, the answer is 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int ans = 0;
        long long x = 1;

        if(l == 0)
            ans++;
        if(k == 1)
            return r - l + 1;

        while(true) {
            long long power = pow(x, k);
            if(power >= l && power <= r)
                ans++;

            if(power > r)
                break;
            x++;
        }

        return ans;
    }
};