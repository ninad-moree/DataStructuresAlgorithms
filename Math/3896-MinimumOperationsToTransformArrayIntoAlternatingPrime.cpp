/*
    You are given an integer array nums. An array is considered alternating prime if: Elements at even indices are prime numbers. Elements at odd indices are non-prime numbers.
    In one operation, you may increment any element by 1. Return the minimum number of operations required to transform nums into an alternating prime array.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: 3
    Explanation: The element at index 0 must be prime. Increment nums[0] = 1 to 2, using 1 operation. The element at index 1 must be non-prime. Increment nums[1] = 2 to 4, 
    using 2 operations. The element at index 2 is already prime. The element at index 3 is already non-prime. Total operations = 1 + 2 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int minOperations(vector<int>& nums) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++) {
            int n = nums[i];
            
            if(i % 2 == 0) {
                while(!isPrime(n)) {
                    n++;
                    ans++;
                }
            } else {
                while(isPrime(n)) {
                    n++;
                    ans++;
                }
            }
        }

        return ans;
    }
};