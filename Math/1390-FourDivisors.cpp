/*
    Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

    Example 1:
    Input: nums = [21,4,7]
    Output: 32
    Explanation: 
    21 has 4 divisors: 1, 3, 7, 21, 4 has 3 divisors: 1, 2, 4, 7 has 2 divisors: 1, 7. The answer is the sum of divisors of 21 only.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(auto num : nums) {
            int div = 0;

            for(int d=2; d*d<=num; d++) {
                if(num%d == 0) {
                    if(div == 0)
                        div= d;
                    else {
                        div = 0;
                        break;
                    }
                }
            }

            if(div > 0 && div != num/div)
                ans += 1 + num + div + num/div;
        }

        return ans;
    }
};