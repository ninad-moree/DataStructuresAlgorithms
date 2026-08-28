/*
    You are given two integers n and k. A positive integer x is called compatible if it satisfies both of the following conditions: abs(n - x) <= k and (n & x) == 0
    Return the sum of all compatible integers x.

    Example 1:
    Input: n = 2, k = 3
    Output: 10
    Explanation: The compatible integers are: x = 1, since abs(2 - 1) = 1 and 2 & 1 = 0. x = 4, since abs(2 - 4) = 2 and 2 & 4 = 0. x = 5, since abs(2 - 5) = 3 and 2 & 5 = 0.
    Thus, the answer is 1 + 4 + 5 = 10.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int x = max(1, n-k);

        while(x <= n+k) {
            if(abs(n-x) <= k && (n & x) == 0)
                ans += x;
            
            x++;
        }

        return ans;
    }
};