/*
    You have n coins and you want to build a staircase with these coins. 
    The staircase consists of k rows where the ith row has exactly i coins. 
    The last row of the staircase may be incomplete.
    Given the integer n, return the number of complete rows of the staircase you will build.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0;
        long long right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = mid * (mid + 1) / 2;

            if (sum == n)
                return static_cast<int>(mid); 
            else if (sum < n)
                left = mid + 1; 
            else 
                right = mid - 1; 
            
        }

        return static_cast<int>(right);
    }
};