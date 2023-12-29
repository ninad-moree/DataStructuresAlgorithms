/*
    Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

    Example 1:
    Inpu: low = 3, high = 7
    Output: 3
    Explanation: The odd numbers between 3 and 7 are [3,5,7].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high && low%2==0)
            return 0;
            
        if (low % 2 == 0) 
            low++;

        int count = (high - low) / 2 + 1;

        return count;
    }
};