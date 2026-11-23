/*
    You are given three integers a, b, and c. You may perform the following operation any number of times (including zero): Choose one of the three integers and replace it with
    the sum of the other two integers. The other two integers remain unchanged. The range of three integers is defined as the difference between the maximum value and the 
    minimum value. Return the minimum range that can be obtained after performing the operation any number of times.

    Example 1:
    Input: a = 9, b = 2, c = 5
    Output: 5
    Explanation: One sequence of operations which results in the minimum range is as follows: Set a to b + c = 2 + 5 = 7. The three integers are now a = 7, b = 2, c = 5.
    The range of the three integers is max(7, 2, 5) - min(7, 2, 5) = 7 - 2 = 5.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRange(int a, int b, int c) {
        int maxi = max({a, b, c});
        int mini = min({a, b, c});
        int mid = a + b + c - maxi - mini;

        if(maxi >= mini + mid)
            return max({mini + mid, mid, mini}) - min({mini + mid, mid, mini});
        else
            return max({maxi, mid, mini}) - min({maxi, mid, mini});
    }
};