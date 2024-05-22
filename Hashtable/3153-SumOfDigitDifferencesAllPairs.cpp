/*
    You are given an array nums consisting of positive integers where all integers have the same number of digits.
    The digit difference between two integers is the count of different digits that are in the same position in the two integers.
    Return the sum of the digit differences between all pairs of integers in nums.

    Example 1:
    Input: nums = [13,23,12]
    Output: 4
    Explanation:
    We have the following:
    - The digit difference between 13 and 23 is 1.
    - The digit difference between 13 and 12 is 1.
    - The digit difference between 23 and 12 is 2.
    So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        int n1 = nums[0];
        string s = to_string(n1);
        int len = s.size();

        long long ans = 0;

        vector<string> str;
        for(auto i : nums)
            str.push_back(to_string(i));

        for(int i=0; i<len; i++) {
            vector<int> freq(10, 0);
            int rem = n;

            for(auto j : str)
                freq[j[i] - '0']++;
            
            for(int k = 0; k<10; k++) {
                if(freq[k] > 0) {
                    ans += freq[k] * (rem - freq[k]);
                    rem -= freq[k];
                }
            }
        }

        return ans;
    }
};