/*
    You are given an integer array nums. A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example 1:
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation: The longest balanced subarray is [2, 5, 4, 3]. It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;

            for(int j=i; j<n; j++) {
                if(nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                if(odd.size() == even.size())
                    ans = max(ans, j-i+1);
            }    
        }

        return ans;
    }
};