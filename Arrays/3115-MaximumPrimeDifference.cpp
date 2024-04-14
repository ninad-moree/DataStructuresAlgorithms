/*
    You are given an integer array nums.
    Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.

    Example 1:
    Input: nums = [4,2,9,5,3]
    Output: 3
    Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) 
            return false;

        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    int maximumPrimeDifference(vector<int>& nums) {
        int leftPrime = -1;
        int rightPrime = -1;
        
        for(int i=0; i<nums.size(); i++) {
            if(isPrime(nums[i])) {
                leftPrime = i;
                break;
            }
        }
        
        for(int i = nums.size()-1; i>=leftPrime; i--) {
            if(isPrime(nums[i])) {
                rightPrime = i;
                break;
            }
        }
        
        return abs(leftPrime - rightPrime);
    }
};