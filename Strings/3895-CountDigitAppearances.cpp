/*
    You are given an integer array nums and an integer digit. Return the total number of times digit appears in the decimal representation of all elements in nums.
    
    Example 1:
    Input: nums = [12,54,32,22], digit = 2
    Output: 4
    Explanation: The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;

        for(auto i : nums) {
            string str = to_string(i);

            for(char ch : str) {
                if(ch - '0' == digit)
                    ans++;
            }
        }

        return ans;
    }
};