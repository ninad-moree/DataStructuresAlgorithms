/*
    Given a positive integer num, return true if num is a perfect square or false otherwise.
    A perfect square is an integer that is the square of an integer. In other words, it is the 
    product of some integer with itself.
    You must not use any built-in library function, such as sqrt.

    Example 1:
    Input: num = 16
    Output: true
    Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num/2;
        if(num == 1 || num == 0)
            return true;
        while(left <= right) {
            long long int mid = (left+right)/2;
            if(mid*mid == num)
                return true;
            else if (mid*mid < num)
                left = mid+1;
            else
                right = mid -1;
        }
        return false;
    }
};