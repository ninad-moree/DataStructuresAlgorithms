/*
    Given an array of integers arr of even length n and an integer k. We want to divide the array into exactly n / 2 pairs such that the sum of 
    each pair is divisible by k. Return true If you can find a way to do that or false otherwise.

    Example 1:
    Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
    Output: true
    Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderFreq(k, 0);

        for (int num : arr) {
            int remainder = ((num % k) + k) % k; 
            remainderFreq[remainder]++;
        }

        for (int i = 1; i < k; ++i) {
            if (remainderFreq[i] != remainderFreq[k - i]) 
                return false;
        }

        if (remainderFreq[0] % 2 != 0) 
            return false;
        
        return true;
    }
};