/*
    You are given two arrays nums1 and nums2 consisting of positive integers.
    You have to replace all the 0's in both arrays with strictly positive integers 
    such that the sum of elements of both arrays becomes equal.
    Return the minimum equal sum you can obtain, or -1 if it is impossible.

    Example 1:
    Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
    Output: 12
    Explanation: We can replace 0's in the following way:
    - Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
    - Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
    Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        
        int zeros1=0;
        int zeros2=0;

        for(auto i : nums1) {
            sum1 += i;
            if(i == 0)
                zeros1++;
        }

        for(auto i : nums2) {
            sum2 += i;
            if(i == 0)
                zeros2++;
        }
        
        if((zeros1==0 && sum1 < sum2+zeros2) || (zeros2==0 && sum2 < sum1+zeros1))
            return -1;

        return max(sum1+zeros1, sum2+zeros2);
    }
};