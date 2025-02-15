/*
    Given a positive integer n, return the punishment number of n. The punishment number of n is defined as the sum of the squares of all integers i 
    such that: 1 <= i <= n The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values 
    of these substrings equals i.

    Example 1:
    Input: n = 10
    Output: 182
    Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
    - 1 since 1 * 1 = 1
    - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
    - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
    Hence, the punishment number of 10 is 1 + 81 + 100 = 182
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(int n, int target) {
        if(target < 0 || n < target)
            return false;

        if(n == target)
            return true;

        return canPartition(n/10, target - n%10) || canPartition(n/100, target - n%100) || canPartition(n/1000, target - n%1000);
    }

    int punishmentNumber(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++) {
            int sq = i * i;

            if(canPartition(sq, i))
                ans += sq;
        }

        return ans;
    }
};