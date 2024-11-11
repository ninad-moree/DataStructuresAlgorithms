/*
    You are given a 0-indexed integer array nums of length n. You can perform the following operation as many times as you want:
        Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
    Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

    Example 1:
    Input: nums = [4,9,6,10]
    Output: true
    Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
    In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0)
                return false;
        }
        
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        for(int i=2; i<= 1000; i++) {
            if(isPrime(i))
                primes.push_back(i);
        }

        for(int i=0; i<nums.size(); i++) {
            if(i==0) {
                int s = primes.size();
                while(s--) {
                    if(primes[s] < nums[i])
                        break;
                }

                if(s == -1)
                    continue;

                nums[i] -= primes[s];
            } else {
                int s = primes.size();
                int x;
                while(s--) {
                    if(nums[i] - primes[s] > nums[i-1] && primes[s] < nums[i]) {
                        x = primes[s];
                        break;
                    }
                }

                if(s >= 0)
                    nums[i] -= x;
            }
        }

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] >= nums[i])
                return false;
        }

        return true;
    }
};