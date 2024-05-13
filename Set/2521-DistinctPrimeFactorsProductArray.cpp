/*
    Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
    Note that:
    A number greater than 1 is called prime if it is divisible by only 1 and itself.
    An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.

    Example 1:
    Input: nums = [2,4,3,7,10,6]
    Output: 4
    Explanation:
    The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
    There are 4 distinct prime factors so we return 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void primeFactors(int n, vector<int>& factors) {
        while (n % 2 == 0) {
            factors.push_back(2);
            n = n / 2;
        }
        
        for (int i = 3; i * i <= n; i = i + 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n = n / i;
            }
        }
        
        if (n > 2)
            factors.push_back(n);
    }

    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        vector<int> pf;

        for(int i=0; i<nums.size(); i++) {
            primeFactors(nums[i], pf);
        }

        for(auto i: pf)
            s.insert(i);

        return s.size();
    }
};